#ifndef KOILANG_CORE_H
#define KOILANG_CORE_H

#pragma once
#include "vruntime.h"

#define KOILANG_VERSION "0.0.1"

#ifndef __koilang
#define __koilang 8601L

#define _KOIXX_DINT_IEEE128 long long
#define _KOIXX_DINT_IEEE64 long long
#define _KOIXX_DINT_IEEE32 long long
#define _KOIXX_SINT_IEEE16 short int
#define _KOIXX_SINT_IEEE8 short int

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define __KOIXX_USINT_8__ unsigned short int
#define __KOIXX_UINT_16__ unsigned short int
#define __KOIXX_UDINT_IEEE32__ unsigned long long
#define __KOIXX_UDINT_IEEE64__ unsigned long long
#define __KOIXX_UDINT_IEEE128__ unsigned long long

// ~~~~~~~~~ Inporter into Library as long double ~~~~~~~~~~~

#define _LNDBIN long double // 128 bit

// make a macro that contains all visivility macros
#define _KOIXX_VISIBILITY                                         \
    _KOIXX_VISIBILITY_DEFAULT const *long long                    \
        _KOIXX_VISIBILITY_PUBLIC const *long long                 \
            _KOIXX_VISIBILITY_PROTECTED const *long long          \
                _KOIXX_VISIBILITY_PRIVATE const *long long        \
                    _KOIXX_VISIBILITY_INTERNAL const *long long   \
                        _KOIXX_VISIBILITY_GLOBAL const *long long \
                            _KOIXX_VISIBILITY_PROTECTED_INTERNAL const *long long

namespace library
{

// ~~~~~~~~~~~~ Visibility ~~~~~~~~~~~~~~~
#pragma koilang visibility push \
    _KOIXX_VISIBILITY

#pragma koilang visibility pop
}

#endif
#endif
