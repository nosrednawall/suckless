void
togglealwaysontop(const Arg *arg)
{
	Client *c = selmon->sel;

	if (!c)
		return;
	if (c->isfullscreen)
	    return;

	c->alwaysontop = !c->alwaysontop;
	restack(selmon);
}
