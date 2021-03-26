#pragma once

#include <sys/types.h>

#include <QtGlobal>
#include <QVariant>

#define QTWEBAPP_MAJOR 1
#define QTWEBAPP_MINOR 7
#define QTWEBAPP_PATCH 3
#define QTWEBAPP_VERSION ((1 << 16) | (7 << 8) | 3)
#define QTWEBAPP_VERSION_STR "1.7.3"

#if defined _WIN32 || defined __CYGWIN__
#  ifdef CMAKE_QTWEBAPP_SO
#    ifdef __GNUC__
#      define QTWEBAPP_EXPORT __attribute__((dllexport))
#    else // __GNUC__
#      define QTWEBAPP_EXPORT __declspec(dllexport)
#    endif // __GNUC__
#  else // CMAKE_QTWEBAPP_SO
#    ifdef __GNUC__
#      define QTWEBAPP_EXPORT __attribute__((dllimport))
#    else // __GNUC__
#      define QTWEBAPP_EXPORT __declspec(dllimport)
#    endif // __GNUC__
#  endif // CMAKE_QSL_SO
#  define QTWEBAPP_PRIVATE
#elif defined __GNUC__ && __GNUC__ >= 4
#  define QTWEBAPP_EXPORT __attribute__((visibility("default")))
#  define QTWEBAPP_PRIVATE __attribute__((visibility("hidden")))
#else
#  define QTWEBAPP_EXPORT
#  define QTWEBAPP_PRIVATE
#endif

namespace qtwebapp {

/// The version of QtWebApp.
QTWEBAPP_EXPORT const char* getQtWebAppLibVersion();

/// Parses the given number by respecting its suffix.
QTWEBAPP_EXPORT int parseNum(const QVariant &v, int base = 1e3);

}
