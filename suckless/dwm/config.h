static const unsigned int borderpx       = 3;
static const unsigned int snap           = 32;
static const unsigned int gappih         = 10;
static const unsigned int gappiv         = 10;
static const unsigned int gappoh         = 10;
static const unsigned int gappov         = 10;
static const int smartgaps               = 0;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft  = 0;
static const unsigned int systrayspacing = 2;
static const int systraypinningfailfirst = 1;
static const int showsystray             = 1;
static const int showbar                 = 1;
static const int topbar                  = 1;
static const char *fonts[]               = { "JetBrainsMono Nerd Font:size=12" };
static const char dmenufont[]            = "JetBrainsMono Nerd Font:size=12";
static const char col_gray1[]            = "#222222";
static const char col_gray2[]            = "#444444";
static const char col_gray3[]            = "#bbbbbb";
static const char col_gray4[]            = "#eeeeee";
static const char col_cyan[]             = "#005577";
static const char col_bg[]               = "#1a1b26";
static const char col_fg[]               = "#a9b1d6";
static const char col_brblk[]            = "#444b6a";
static const char col_cyn[]              = "#0db9d7";
static const char col_mag[]              = "#ad8ee6";
static const char col_p[]		 = "#f6a0ca";

static const char *colors[][3]      = {
	[SchemeNorm] = { col_fg,  col_bg, col_brblk },
	[SchemeSel]  = { col_p, col_bg, col_p  },
};

static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

static const float mfact        = 0.50;
static const int nmaster        = 1;
static const int resizehints    = 0;
static const int lockfullscreen = 1;
static const int refreshrate    = 120;

static const Layout layouts[] = {
	{ "󰝘",      tile },
	{ "",      NULL }, 
	{ "[M]",    monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] =   { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_mag, "-sf", col_gray4, NULL };
static const char *termcmd[]  =   { "st", NULL };
static const char *firefoxcmd[] = { "firefox", NULL };
static const char *thunarcmd[]  = { "thunar", NULL };
static const char *screenshotcmd[] = { "/bin/sh", "-c", "maim -s | xclip -selection clipboard -t image/png", NULL };

static const Key keys[] = {
	{ MODKEY|ShiftMask, XK_Return, spawn,      {.v = dmenucmd } },
	{ MODKEY,           XK_Return, spawn,      {.v = termcmd } },
	{ MODKEY,           XK_b,      spawn,      {.v = firefoxcmd } },
	{ MODKEY,           XK_e,      spawn,      {.v = thunarcmd } },
	{ MODKEY,           XK_s,      spawn,      {.v = screenshotcmd } },
	{ MODKEY,           XK_j,      focusstack, {.i = +1 } },
	{ MODKEY,           XK_k,      focusstack, {.i = -1 } },
	{ MODKEY,           XK_i,      incnmaster, {.i = +1 } },
	{ MODKEY,           XK_d,      incnmaster, {.i = -1 } },
	{ MODKEY,           XK_h,      setmfact,   {.f = -0.05 } },
	{ MODKEY,           XK_l,      setmfact,   {.f = +0.05 } },
	{ MODKEY,           XK_p,      zoom,       {0} },
	{ MODKEY,           XK_q,      killclient, {0} },
	{ MODKEY,           XK_t,      setlayout,  {.v = &layouts[0]} },
	{ MODKEY,           XK_f,      setlayout,  {.v = &layouts[1]} },
	{ MODKEY,           XK_m,      setlayout,  {.v = &layouts[2]} },
	{ MODKEY,           XK_comma,  focusmon,   {.i = -1 } },
	{ MODKEY,           XK_period, focusmon,   {.i = +1 } },
	{ MODKEY|ShiftMask, XK_comma,  tagmon,     {.i = -1 } },
	{ MODKEY|ShiftMask, XK_period, tagmon,     {.i = +1 } },
	TAGKEYS(            XK_1,                  0)
	TAGKEYS(            XK_2,                  1)
	TAGKEYS(            XK_3,                  2)
	TAGKEYS(            XK_4,                  3)
	TAGKEYS(            XK_5,                  4)
	TAGKEYS(            XK_6,                  5)
	TAGKEYS(            XK_7,                  6)
	TAGKEYS(            XK_8,                  7)
	TAGKEYS(            XK_9,                  8)
	{ MODKEY|ShiftMask, XK_q,      quit,       {0} },
};

static const Button buttons[] = {
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

