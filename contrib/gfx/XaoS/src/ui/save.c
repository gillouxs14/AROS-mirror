#ifndef _plan9_
#ifndef AROS
#include <limits.h>
#endif
#include <string.h>
#include <errno.h>
#ifndef AROS
#include <malloc.h>
#endif
#else
#include <u.h>
#include <libc.h>
#endif
#include <filter.h>
#include <fractal.h>
#include <ui_helper.h>
#include <config.h>
#include <version.h>
static int first = 0;
static int changed;
static int last;
char *save_fastmode[] =
{"zero", "never", "animation", "new", "allways"};
char *xtextposnames[] =
{"left", "center", "right", NULL};
char *ytextposnames[] =
{"top", "middle", "bottom", NULL};
// static void outputerror (struct uih_context *uih) REGISTERS (3);
static void outputerror (struct uih_context *uih)
{
  static char error[245];
  if (uih->savec->writefailed)
    return;
  sprintf (error, "Write failed:%s", xio_errorstring());
  uih->errstring = error;
  uih->savec->writefailed = 1;
}
// static void start_save (struct uih_context *uih, char *name) REGISTERS (3);
static void start_save (struct uih_context *uih, char *name)
{
  if (!changed && !uih->savec->firsttime)
    {
      myprintf ("\n(usleep %i)\n", tl_lookup_timer (uih->savec->timer));
      tl_reset_timer (uih->savec->timer);
    }
  changed = 1;
  myputc ('(');
  myputs (name);
  first = 0;
}
// static void stop_save (struct uih_context *uih) REGISTERS (3);
static void stop_save (struct uih_context *uih)
{
  myputc (')');
  myputc ('\n');
}
#ifdef SAVEKEYWORDUSED
// static void save_keyword (struct uih_context *uih, char *name) REGISTERS (3);
static void save_keyword (struct uih_context *uih, char *name)
{
  if (!first)
    myputc (' ');
  else
    first = 0;
  myputs (name);
}
#endif
// static void save_keystring (struct uih_context *uih, char *name) REGISTERS (3);
static void save_keystring (struct uih_context *uih, char *name)
{
  if (!first)
    myputc (' ');
  else
    first = 0;
  myputc ('\'');
  myputs (name);
}
// static void save_float (struct uih_context *uih, number_t number) REGISTERS (3);
static void save_float (struct uih_context *uih, number_t number)
{
  if (!first)
    myputc (' ');
  else
    first = 0;
#ifdef HAVE_LONG_DOUBLE
  /*20 should be enought to specify 64digit number :) */
  myprintf ("%.20LG", (long double) number);
#else
  myprintf ("%.20G", (double) number);
#endif
}
// static void save_float2 (struct uih_context *uih, number_t number, int places) REGISTERS (3);
static void save_float2 (struct uih_context *uih, number_t number, int places)
{
  char fs[10];
  if (!first)
    myputc (' ');
  else
    first = 0;
  if (places < 0)
    places = 0;
  if (places > 20)
    places = 20;
#ifdef HAVE_LONG_DOUBLE
  sprintf (fs, "%%.%iLG", places);
  myprintf (fs, (long double) number);
#else
  sprintf (fs, "%%.%iG", places);
  myprintf (fs, (double) number);
#endif
}
// static void save_int (struct uih_context *uih, int number) REGISTERS (3);
static void save_int (struct uih_context *uih, int number)
{
  if (!first)
    myputc (' ');
  else
    first = 0;
  myprintf ("%i", number);
}
// static void save_onoff (struct uih_context *uih, int number) REGISTERS (3);
static void save_onoff (struct uih_context *uih, int number)
{
  if (!first)
    myputc (' ');
  else
    first = 0;
  myputs (number ? "#t" : "#f");
}
// static void save_string (struct uih_context *uih, char *text) REGISTERS (3);
static void save_string (struct uih_context *uih, char *text)
{
  int i = 0;
  if (!first)
    myputc (' ');
  else
    first = 0;
  myputc ('"');
  while (text[i] != 0)
    {
      if (text[i] == '"')
	myputc ('\\');
      myputc (text[i]);
      i++;
    }
  myputc ('"');
}
// static void save_intc (struct uih_context *uih, char *name, int number) REGISTERS (3);
static void save_intc (struct uih_context *uih, char *name, int number)
{
  start_save (uih, name);
  save_int (uih, number);
  stop_save (uih);
}
// static void save_onoffc (struct uih_context *uih, char *name, int number) REGISTERS (3);
static void save_onoffc (struct uih_context *uih, char *name, int number)
{
  start_save (uih, name);
  save_onoff (uih, number);
  stop_save (uih);
}
// static void save_floatc (struct uih_context *uih, char *name, number_t number) REGISTERS (3);
static void save_floatc (struct uih_context *uih, char *name, number_t number)
{
  start_save (uih, name);
  save_float (uih, number);
  stop_save (uih);
}
// static void save_float2c (struct uih_context *uih, char *name, number_t number, int places) REGISTERS (3);
static void save_float2c (struct uih_context *uih, char *name, number_t number, int places)
{
  start_save (uih, name);
  save_float2 (uih, number, places);
  stop_save (uih);
}
// static void save_coordc (struct uih_context *uih, char *name, number_t number, number_t number2) REGISTERS (3);
static void save_coordc (struct uih_context *uih, char *name, number_t number, number_t number2)
{
  start_save (uih, name);
  save_float (uih, number);
  save_float (uih, number2);
  stop_save (uih);
}
// static void save_keystringc (struct uih_context *uih, char *name, char *param) REGISTERS (3);
static void save_keystringc (struct uih_context *uih, char *name, char *param)
{
  start_save (uih, name);
  save_keystring (uih, param);
  stop_save (uih);
}
// static void save_stringc (struct uih_context *uih, char *name, char *param) REGISTERS (3);
static void save_stringc (struct uih_context *uih, char *name, char *param)
{
  start_save (uih, name);
  save_string (uih, param);
  stop_save (uih);
}
// static void save_noparam (struct uih_context *uih, char *name) REGISTERS (3);
static void save_noparam (struct uih_context *uih, char *name)
{
  start_save (uih, name);
  stop_save (uih);
}
// static void save_nstring (struct uih_context *uih, int number, char **texts) REGISTERS (3);
static void save_nstring (struct uih_context *uih, int number, char **texts)
{
  save_keystring (uih, texts[number]);
}
// static void save_nstringc (struct uih_context *uih, char *name, int number, char **texts) REGISTERS (3);
static void save_nstringc (struct uih_context *uih, char *name, int number, char **texts)
{
  save_keystringc (uih, name, texts[number]);
}
static int
ndecimals (struct uih_context *uih)
{
  number_t n = 10000;
  number_t m = uih->fcontext->s.rr;
  int i;
  if (uih->fcontext->s.ri < m)
    m = uih->fcontext->s.ri;
  if (uih->fcontext->s.ri > 100 || uih->fcontext->s.rr > 100)
    return (20);
  for (i = 0; i < 20 && m < n; i++, n /= 10);
  return (i);
}
// static void savepos (struct uih_context *uih) REGISTERS (3);
static void savepos (struct uih_context *uih)
{
  int n = ndecimals (uih);
  start_save (uih, "view");
  save_float2 (uih, uih->fcontext->s.cr, n);
  save_float2 (uih, uih->fcontext->s.ci, n);
  save_float2 (uih, uih->fcontext->s.rr, n);
  save_float2 (uih, uih->fcontext->s.ri, n);
  stop_save (uih);
  uih->savec->fcontext->s = uih->fcontext->s;
}
// static void savepos2 (struct uih_context *uih) REGISTERS (3);
static void savepos2 (struct uih_context *uih)
{
  int n = ndecimals (uih);
  start_save (uih, "animateview");
  save_float2 (uih, uih->fcontext->s.cr, n);
  save_float2 (uih, uih->fcontext->s.ci, n);
  save_float2 (uih, uih->fcontext->s.rr, n);
  save_float2 (uih, uih->fcontext->s.ri, n);
  stop_save (uih);
  uih->savec->fcontext->s = uih->fcontext->s;
}
// static void savepos3 (struct uih_context *uih) REGISTERS (3);
static void savepos3 (struct uih_context *uih)
{
  int n = ndecimals (uih);
  start_save (uih, "morphview");
  save_float2 (uih, uih->fcontext->s.cr, n);
  save_float2 (uih, uih->fcontext->s.ci, n);
  save_float2 (uih, uih->fcontext->s.rr, n);
  save_float2 (uih, uih->fcontext->s.ri, n);
  stop_save (uih);
  uih->savec->fcontext->s = uih->fcontext->s;
}
void
uih_saveframe (struct uih_context *uih)
{
  struct uih_savedcontext *s = uih->savec;
  int i;
  int resetsync = 0;
  if (uih->save)
    {
      changed = 0;
      if (s->firsttime)
	save_noparam (uih, "initstate");
      if (s->nonfractalscreen && !uih->nonfractalscreen)
	save_noparam (uih, "display"), s->nonfractalscreen = 0;
      for (i = 0; i < uih_nfilters; i++)
	{
	  if (uih->filter[i] != NULL)
	    {
	      if (s->filter[i] != 1)
		{
		  start_save (uih, "filter");
		  save_keystring (uih, uih->filter[i]->action->shortname);
		  save_onoff (uih, 1);
		  s->filter[i] = 1;
		  stop_save (uih);
		}
	    }
	  else if (s->filter[i] != 0)
	    {
	      s->filter[i] = 0;
	      start_save (uih, "filter");
	      save_keystring (uih, uih_filters[i]->shortname);
	      save_onoff (uih, 0);
	      stop_save (uih);
	    }
	}
      if (uih->palettechanged)
	{
	  switch (uih->palettetype)
	    {
	    case 0:
	      save_intc (uih, "defaultpalette", uih->paletteshift);
	      break;
	    default:
	      start_save (uih, "palette");
	      save_int (uih, uih->palettetype);
	      save_int (uih, uih->paletteseed);
	      save_int (uih, uih->paletteshift);
	      stop_save (uih);
	      break;
	    }
	  uih->palettechanged = 0;
	}
      if (s->fcontext->currentformula != uih->fcontext->currentformula)
	{
	  save_keystringc (uih, "formula", uih->fcontext->currentformula->shortname), s->fcontext->currentformula = uih->fcontext->currentformula;
	  set_formula (s->fcontext, uih->fcontext->currentformula - formulas);
	}
      if (s->mode >= UIH_SAVEALL)
	save_intc (uih, "letterspersec", uih->letterspersec);
      if (s->mode > UIH_SAVEPOS)
	{
	  if (s->speedup != uih->speedup)
	    save_floatc (uih, "speedup", uih->speedup), s->speedup = uih->speedup;
	  if (s->maxstep != uih->maxstep)
	    save_floatc (uih, "maxstep", uih->maxstep), s->maxstep = uih->maxstep;
	  if (s->fastmode != uih->fastmode)
	    save_nstringc (uih, "fastmode", uih->fastmode, save_fastmode), s->fastmode = uih->fastmode;
	}
      if (s->juliamode != uih->juliamode)
	save_onoffc (uih, "fastjulia", uih->juliamode), s->juliamode = uih->juliamode;
      if (s->cycling != uih->cycling)
	save_onoffc (uih, "cycling", uih->cycling), s->cycling = uih->cycling;
      if (s->mode >= UIH_SAVEPOS && s->fcontext->periodicity != uih->fcontext->periodicity)
	save_onoffc (uih, "periodicity", uih->fcontext->periodicity), s->fcontext->periodicity = uih->fcontext->periodicity;
      if ((uih->cycling || s->mode >= UIH_SAVEALL) && (s->cyclingspeed != uih->cyclingspeed || s->direction != uih->direction))
	save_intc (uih, "cyclingspeed", uih->cyclingspeed), s->cyclingspeed = uih->cyclingspeed, s->direction = uih->direction;
      if ((s->mode > UIH_SAVEPOS && (uih->step || uih->zoomactive)) && (s->xcenter != uih->xcenter || s->ycenter != uih->ycenter))
	save_coordc (uih, "zoomcenter", uih->xcenter, uih->ycenter), s->xcenter = uih->xcenter, s->ycenter = uih->ycenter;
      if ((!uih->fcontext->mandelbrot || uih->juliamode) && (s->fcontext->pre != uih->fcontext->pre || s->fcontext->pim != uih->fcontext->pim))
	{
	  if (uih->juliamode && uih->pressed)
	    save_coordc (uih, "morphjulia", uih->fcontext->pre, uih->fcontext->pim), s->fcontext->pre = uih->fcontext->pre, s->fcontext->pim = uih->fcontext->pim;
	  else
	    save_coordc (uih, "juliaseed", uih->fcontext->pre, uih->fcontext->pim), s->fcontext->pre = uih->fcontext->pre, s->fcontext->pim = uih->fcontext->pim;
	}
      if (uih->fcontext->bre != s->fcontext->bre || uih->fcontext->bim != s->fcontext->bim)
	{
	  save_coordc (uih, "perturbation", uih->fcontext->bre, uih->fcontext->bim), s->fcontext->bre = uih->fcontext->bre, s->fcontext->bim = uih->fcontext->bim;
	}
      if (uih->fastrotate != s->fastrotate && s->mode > UIH_SAVEPOS)
	{
	  save_onoffc (uih, "fastrotate", uih->fastrotate);
	  s->fastrotate = uih->fastrotate;
	}
      if (uih->fcontext->angle != s->fcontext->angle && s->autorotate != 1)
	{
	  if (s->rotatepressed && s->mode == UIH_SAVEANIMATION)
	    save_float2c (uih, "morphangle", uih->fcontext->angle, 5);
	  else
	    save_float2c (uih, "angle", uih->fcontext->angle, 5);
	  s->rotatepressed = uih->rotatepressed;
	  s->fcontext->angle = uih->fcontext->angle;
	}
      if (uih->rotationspeed != s->rotationspeed && ((s->mode > UIH_SAVEPOS && uih->rotatemode == ROTATE_CONTINUOUS) || s->mode >= UIH_SAVEALL))
	{
	  save_float2c (uih, "rotationspeed", uih->rotationspeed, 6);
	  s->rotationspeed = uih->rotationspeed;
	}
      if (s->autorotate != (uih->rotatemode == ROTATE_CONTINUOUS))
	{
	  s->autorotate = (uih->rotatemode == ROTATE_CONTINUOUS);
	  save_onoffc (uih, "autorotate", s->autorotate);
	}
      if (s->fcontext->maxiter != uih->fcontext->maxiter)
	save_intc (uih, "maxiter", uih->fcontext->maxiter), s->fcontext->maxiter = uih->fcontext->maxiter;
      if (s->fcontext->coloringmode != uih->fcontext->coloringmode)
	save_intc (uih, "outcoloring", uih->fcontext->coloringmode), s->fcontext->coloringmode = uih->fcontext->coloringmode;
      if (s->fcontext->incoloringmode != uih->fcontext->incoloringmode)
	save_intc (uih, "incoloring", uih->fcontext->incoloringmode), s->fcontext->incoloringmode = uih->fcontext->incoloringmode;
      if (s->fcontext->incoloringmode != uih->fcontext->incoloringmode)
	save_intc (uih, "incoloring", uih->fcontext->incoloringmode), s->fcontext->incoloringmode = uih->fcontext->incoloringmode;
      if ((s->fcontext->incoloringmode == 10 || s->mode >= UIH_SAVEALL) && s->fcontext->intcolor != uih->fcontext->intcolor)
	save_intc (uih, "intcoloring", uih->fcontext->intcolor), s->fcontext->intcolor = uih->fcontext->intcolor;
      if ((s->fcontext->coloringmode == 10 || s->mode >= UIH_SAVEALL) && s->fcontext->outtcolor != uih->fcontext->outtcolor)
	save_intc (uih, "outtcoloring", uih->fcontext->outtcolor), s->fcontext->outtcolor = uih->fcontext->outtcolor;

      if (s->fcontext->mandelbrot != uih->fcontext->mandelbrot)
	save_onoffc (uih, "julia", !uih->fcontext->mandelbrot), s->fcontext->mandelbrot = uih->fcontext->mandelbrot;
      if (s->mode > UIH_SAVEPOS && s->fcontext->range != uih->fcontext->range)
	save_intc (uih, "range", uih->fcontext->range), s->fcontext->range = uih->fcontext->range;
      if (s->fcontext->plane != uih->fcontext->plane)
	save_intc (uih, "plane", uih->fcontext->plane), s->fcontext->plane = uih->fcontext->plane;
      if (s->zoomactive != uih->zoomactive && s->mode > UIH_SAVEPOS)
	{
	  switch (uih->zoomactive)
	    {
	    case -1:
	      save_noparam (uih, "unzoom");
	      break;
	    case 1:
	      save_noparam (uih, "zoom");
	      break;
	    default:
	      save_noparam (uih, "stop");
	      break;
	    }
	  s->zoomactive = uih->zoomactive;
	}
      if ((s->xtextpos != uih->xtextpos || s->ytextpos != uih->ytextpos) &&
	  (s->mode > UIH_SAVEANIMATION || (s->mode == UIH_SAVEANIMATION && s->displaytext)))
	{
	  start_save (uih, "textpossition");
	  save_nstring (uih, uih->xtextpos, xtextposnames);
	  save_nstring (uih, uih->ytextpos, ytextposnames);
	  stop_save (uih);
	  s->xtextpos = uih->xtextpos;
	  s->ytextpos = uih->ytextpos;
	}
      if (s->clearscreen)
	{
	  save_noparam (uih, "clearscreen");
	  s->clearscreen = 0;
	  s->nonfractalscreen = 1;
	}
      if (s->displaytext)
	{
	  save_stringc (uih, "text", s->text);
	  s->displaytext = 0;
	  s->nonfractalscreen = 1;
	  free (s->text);
	  save_noparam (uih, "textsleep");
	}
      if (s->autorotate && changed && tl_lookup_timer (uih->savec->synctimer) > 500000)
	save_float2c (uih, "angle", uih->fcontext->angle, 5), resetsync = 1;
      if (s->mode == UIH_SAVEPOS)
	savepos (uih);
      else
	{
	  if (uih->viewchanged)
	    savepos (uih), uih->viewchanged = 0;
	  else if (uih->moved)
	    savepos3 (uih), uih->moved = 0;
	  else if (((changed && uih->step) || last) && tl_lookup_timer (uih->savec->synctimer) > 500000)
	    resetsync = 1, savepos2 (uih);
	}
      if (uih->savec->firsttime)
	uih->savec->firsttime = 0;
      if (s->writefailed)
	uih_save_disable (uih);
      if (resetsync)
	tl_reset_timer (uih->savec->synctimer);
    }				/*if uih->save */
}
int
uih_save_enable (struct uih_context *uih, xio_file f, int mode)
{
  struct uih_savedcontext *s;
  int i;
  last = 0;
  if (uih->save)
    {
      uih->errstring = "Recording is already enabled";
      return 0;
    }
  s = (struct uih_savedcontext *) calloc (sizeof (*s), 1);
  if (f == NULL || s == NULL)
    {
      uih->errstring = "File could not be opended or out of memory";
      return 0;
    }
  uih->savec = s;
  s->fcontext = make_fractalc (1, uih->image->pixelwidth * uih->image->width, uih->image->pixelheight * uih->image->height);
  if (s->fcontext == NULL)
    {
      uih->errstring = "File could not be opended or out of memory";
      free (s);
      return 0;
    }
  s->mode = mode;
  /*Invalidate context to force save everything first */
  s->speedup = STEP;
  s->maxstep = MAXSTEP;
  s->xcenter = INT_MAX;
  s->fastmode = 2;
  s->juliamode = 0;
  s->cycling = 0;
  for (i = 0; i < uih_nfilters; i++)
    s->filter[i] = 0;
  s->pressed = 0;
  s->firsttime = 1;
  uih->palettechanged = 1;
  s->cyclingspeed = 30;
  s->fcontext->pre = s->fcontext->pim = 0;
  s->fcontext->bre = s->fcontext->bim = 0;
  s->fcontext->currentformula = NULL;
  s->fcontext->periodicity = 1;
  s->fcontext->maxiter = 170;
  s->fcontext->coloringmode = 0;
  s->fcontext->incoloringmode = 0;
  s->fcontext->outtcolor = 1;
  s->fcontext->intcolor = 1;
  s->fcontext->mandelbrot = 1;
  s->fcontext->plane = 0;
  s->fcontext->range = 3;
  s->fcontext->angle = 0;
  s->rotatepressed = 0;
  s->autorotate = 0;
  s->fastrotate = 0;
  s->rotationspeed = 10;
  s->displaytext = 0;
  s->clearscreen = 0;
  s->xtextpos = 1;
  s->ytextpos = 1;
  s->file = f;
  s->timer = tl_create_timer ();
  s->synctimer = tl_create_timer ();
  tl_reset_timer (s->timer);
  uih->viewchanged = 1;
  uih->palettechanged = 1;
  uih->save = 1;
  uih->moved = 0;
#ifndef _plan9_
  if (mode == UIH_SAVEANIMATION)
    myputs (";Animation file automatically generated by XaoS " XaoS_VERSION "\n"
	    ";  - an realtime interactive fractal zoomer\n"
	    ";Use xaos -play <filename> to replay it\n");
  else if (mode == UIH_SAVEPOS)
    myputs (";Possition file automatically generated by XaoS " XaoS_VERSION "\n"
	    ";  - an realtime interactive fractal zoomer\n"
	    ";Use xaos -load <filename> to display it\n");
#endif
  uih_saveframe (uih);
  putc ('\n', f);
  return 1;
}
void
uih_save_disable (struct uih_context *uih)
{
  if (uih->save)
    {
      last = 1;
      if (uih->savec->mode >= UIH_SAVEANIMATION)
	uih_saveframe (uih);
      if (xio_close (uih->savec->file))
	outputerror (uih);
      uih->save = 0;
      free (uih->savec->fcontext);
      tl_free_timer (uih->savec->timer);
      tl_free_timer (uih->savec->synctimer);
      free (uih->savec);
    }
}
void
uih_save_possition (struct uih_context *uih, xio_file f, int mode)
{
  uih_save_enable (uih, f, mode);
  uih_save_disable (uih);
}
