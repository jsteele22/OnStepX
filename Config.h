//
// Configuration Selector.
//
// Platformio generates command line flags, e.g. -DLOSMANDY
//
// Otherwise, uncomment *one* MANUAL_CHOICE below
//


//#define MANUAL_CHOICE LOSMANDY
//#define MANUAL_CHOICE CELESTRON


// This is the original Config.h, unmodified.
// Other Config.h.* files simply re-define particular macros.

#include "Config.h.defaults"

#if defined(LOSMANDY)

  #include "Config.h.Losmandy"

#elif defined(CELESTRON)

  #include "Config.h.Celestron"

#elif !defined(MANUAL_CHOICE)

    #error "Edit Config.h to select a configuration."

#elif (MANUAL_CHOICE == LOSMANDY)

  #define LOSMANDY
  #include "Config.h.Losmandy"

#elif (MANUAL_CHOICE == CELESTRON)

  #define CELESTRON
  #include "Config.h.Celestron"

#else

  #error "Config.h: Unknown value for MANUAL_CHOICE"

#endif
