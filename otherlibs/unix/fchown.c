/***********************************************************************/
/*                                                                     */
/*                                OCaml                                */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id$ */

#include <fail.h>
#include <mlvalues.h>
#include "unixsupport.h"

#ifdef HAS_FCHMOD

CAMLprim value unix_fchown_r(CAML_R, value fd, value uid, value gid)
{
  if (fchown(Int_val(fd), Int_val(uid), Int_val(gid)) == -1)
    uerror_r(ctx,"fchown", Nothing);
  return Val_unit;
}

#else

CAMLprim value unix_fchown_r(CAML_R, value fd, value uid, value gid)
{ caml_invalid_argument_r(ctx,"fchown not implemented"); }

#endif
