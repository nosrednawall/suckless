int
width_tags(Bar *bar, BarArg *a)
{
	int w, i;
	Client *c;
	unsigned int occ = 0;
	for (c = bar->mon->clients; c; c = c->next)
		occ |= c->tags == 255 ? 0 : c->tags;

	for (w = 0, i = 0; i < NUMTAGS; i++) {
		if (!(occ & 1 << i || bar->mon->tagset[bar->mon->seltags] & 1 << i))
			continue;
		w += TEXTW(tagicon(bar->mon, i));
	}
	return w;
}

int
draw_tags(Bar *bar, BarArg *a)
{
	int invert;
	int w, x = a->x;
	unsigned int i, occ = 0, urg = 0;
	char *icon;
	Client *c;
	Monitor *m = bar->mon;

	for (c = m->clients; c; c = c->next) {
		occ |= c->tags == 255 ? 0 : c->tags;
		if (c->isurgent)
			urg |= c->tags;
	}
	for (i = 0; i < NUMTAGS; i++) {
		/* do not draw vacant tags */
		if (!(occ & 1 << i || m->tagset[m->seltags] & 1 << i))
			continue;

		icon = tagicon(bar->mon, i);
		invert = 0;
		w = TEXTW(icon);
		drw_setscheme(drw, scheme[
			m->tagset[m->seltags] & 1 << i
			? SchemeTagsSel
			: urg & 1 << i
			? SchemeUrg
			: SchemeTagsNorm
		]);
		drw_text(drw, x, a->y, w, a->h, lrpad / 2, icon, invert, False);
		drawindicator(m, NULL, occ, x, a->y, w, a->h, i, -1, invert, tagindicatortype);
		if (ulineall || m->tagset[m->seltags] & 1 << i)
			drw_rect(drw, x + ulinepad, a->y + bh - ulinestroke - ulinevoffset, w - (ulinepad * 2), ulinestroke, 1, 0);
		x += w;
	}

	return 1;
}

int
click_tags(Bar *bar, Arg *arg, BarArg *a)
{
	int i = 0, x = 0;
	Client *c;
	unsigned int occ = 0;
	for (c = bar->mon->clients; c; c = c->next)
		occ |= c->tags == 255 ? 0 : c->tags;

	do {
		if (!(occ & 1 << i || bar->mon->tagset[bar->mon->seltags] & 1 << i))
			continue;
		x += TEXTW(tagicon(bar->mon, i));
	} while (a->x >= x && ++i < NUMTAGS);
	if (i < NUMTAGS) {
		arg->ui = 1 << i;
	}
	if (selmon->previewshow != 0) {
		hidetagpreview(selmon);
	}
	return ClkTagBar;
}

int
hover_tags(Bar *bar, BarArg *a, XMotionEvent *ev)
{
	int i = 0, x = lrpad / 2;
	int px, py;
	Monitor *m = bar->mon;
	int ov = gappov;
	int oh = gappoh;

	Client *c;
	unsigned int occ = 0;
	for (c = bar->mon->clients; c; c = c->next)
		occ |= c->tags == 255 ? 0 : c->tags;

	do {
		if (!(occ & 1 << i || bar->mon->tagset[bar->mon->seltags] & 1 << i))
			continue;
		x += TEXTW(tagicon(bar->mon, i));
	} while (a->x >= x && ++i < NUMTAGS);

	if (i < NUMTAGS) {
		if ((i + 1) != selmon->previewshow && !(selmon->tagset[selmon->seltags] & 1 << i)) {
			if (bar->by > m->my + m->mh / 2) // bottom bar
				py = bar->by - m->mh / scalepreview - oh;
			else // top bar
				py = bar->by + bar->bh + oh;
			px = bar->bx + ev->x - m->mw / scalepreview / 2;
			if (px + m->mw / scalepreview > m->mx + m->mw)
				px = m->wx + m->ww - m->mw / scalepreview - ov;
			else if (px < bar->bx)
				px = m->wx + ov;
			selmon->previewshow = i + 1;
			showtagpreview(i, px, py);
		} else if (selmon->tagset[selmon->seltags] & 1 << i) {
			hidetagpreview(selmon);
		}
	} else if (selmon->previewshow != 0) {
		hidetagpreview(selmon);
	}

	return 1;
}
