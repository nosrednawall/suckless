void
buttonpress(XEvent *e)
{
	struct item *item;
	XButtonPressedEvent *ev = &e->xbutton;
	int x = 0, y = 0, h = bh, w;
	int i, cols;

	if (ev->window != win) {
		/* automatically close dmenu if the user clicks outside of dmenu, but
		 * ignore the scroll wheel and buttons above that */
		if (ev->button <= Button3) {
			exit(1);
		}
		return;
	}

	/* right-click: exit */
	if (ev->button == Button3)
		exit(1);

	if (prompt && *prompt)
		x += promptw;

	/* input field */
	w = (lines > 0 || !matches) ? mw - x : inputw;

	/* left-click on input: clear input,
	 * NOTE: if there is no left-arrow the space for < is reserved so
	 *       add that to the input width */
	if (ev->button == Button1 &&
	   ((lines <= 0 && ev->x >= 0 && ev->x <= x + w +
	   ((!prev || !curr->left) ? TEXTW("<") : 0)) ||
	   (lines > 0 && ev->y >= y && ev->y <= y + h))) {
		insert(NULL, -cursor);
		drawmenu();
		return;
	}
	/* middle-mouse click: paste selection */
	if (ev->button == Button2) {
		XConvertSelection(dpy, (ev->state & ShiftMask) ? clip : XA_PRIMARY,
		                  utf8, utf8, win, CurrentTime);
		drawmenu();
		return;
	}
	/* scroll up */
	if (ev->button == Button4 && prev) {
		sel = curr = prev;
		calcoffsets();
		drawmenu();
		return;
	}
	/* scroll down */
	if (ev->button == Button5 && next) {
		sel = curr = next;
		calcoffsets();
		drawmenu();
		return;
	}
	if (ev->button != Button1)
		return;
	if (ev->state & ShiftMask)
		return;
	if (lines > 0) {
		cols = columns ? columns : 1;
		for (i = 0, item = curr; item != next; item = item->right, i++) {
			if (
				(ev->y >= y + ((i % lines) + 1) * bh) && // line y start
				(ev->y <= y + ((i % lines) + 2) * bh) && // line y end
				(ev->x >= x + ((i / lines) * (w / cols))) && // column x start
				(ev->x <= x + ((i / lines + 1) * (w / cols))) // column x end
			) {
				clickitem(item, ev);
				return;
			}
		}
	} else if (matches) {
		/* left-click on left arrow */
		x += inputw;
		w = TEXTW("<");
		if (prev && curr->left) {
			if (ev->x >= x && ev->x <= x + w) {
				sel = curr = prev;
				calcoffsets();
				drawmenu();
				return;
			}
		}
		/* horizontal list: (ctrl)left-click on item */
		for (item = curr; item != next; item = item->right) {
			x += w;
			w = MIN(TEXTW(item->text), mw - x - TEXTW(">"));
			if (ev->x >= x && ev->x <= x + w) {
				clickitem(item, ev);
				return;
			}
		}
		/* left-click on right arrow */
		w = TEXTW(">");
		x = mw - w;
		if (next && ev->x >= x && ev->x <= x + w) {
			sel = curr = next;
			calcoffsets();
			drawmenu();
			return;
		}
	}
}

static void
clickitem(struct item *item, XButtonEvent *ev)
{

	puts(item->text);

	sel = item;
	if (!(ev->state & ControlMask)) {
		cleanup();
		exit(0);
	}

	sel->out = 1;
	drawmenu();
}

void
motionevent(XButtonEvent *ev)
{
	struct item *item;
	int x = 0, y = 0, w;
	int i, cols;

	if (ev->window != win || matches == 0)
		return;

	if (prompt && *prompt)
		x += promptw;

	if (lines > 0) {
		/* input field */
		w = mw - x;
		cols = columns ? columns : 1;
		/* grid view or vertical list */
		for (i = 0, item = curr; item != next; item = item->right, i++) {
			if (
				(ev->y >= y + ((i % lines) + 1) * bh) && // line y start
				(ev->y <= y + ((i % lines) + 2) * bh) && // line y end
				(ev->x >= x + ((i / lines) * (w / cols))) && // column x start
				(ev->x <= x + ((i / lines + 1) * (w / cols))) // column x end
			) {
				sel = item;
				calcoffsets();
				drawmenu();
				break;
			}
		}
		return;
	}

	/* left-click on left arrow */
	x += inputw;
	w = TEXTW("<");
	/* horizontal list */
	for (item = curr; item != next; item = item->right) {
		x += w;
		w = MIN(TEXTW(item->text), mw - x - TEXTW(">"));
		if (ev->x >= x && ev->x <= x + w) {
			sel = item;
			calcoffsets();
			drawmenu();
			break;
		}
	}
}
