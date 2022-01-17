#ifndef __TYPES__H__
#define __TYPES__H__

#ifndef BIT
#define BIT(nr)             (1UL << (nr))
#endif  /* !BIT */

#ifndef FIELD
#define FIELD(v, nr)        ((v) << (nr))
#endif  /* !FIELD */

#ifndef EXTRACT
#define EXTRACT(v, nr, m)   (((v) >> (nr)) & m)
#endif  /* !EXTRACT */

#include <stdint.h>
#include <stdbool.h>

#endif  //!__TYPES__H__
