AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

bin_PROGRAMS = p44maintd

# p44maintd

if DEBUG
p44maintd_DEBUG = -D DEBUG=1
endif

if P44_BUILD_OW
p44maintd_PLATFORM = -D P44_BUILD_OW=1
endif

if WITH_APPLICATION_VERSION
p44maintd_VERSION = -DP44_APPLICATION_VERSION=\"$(APPLICATION_VERSION)\"
endif


p44maintd_LDADD = ${JSONC_LIBS} ${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
p44maintd_EXTRACFLAGS = -D BOOST_BIND_GLOBAL_PLACEHOLDERS=1


p44maintd_CPPFLAGS = \
  -I ${srcdir}/src/p44utils \
  -I ${srcdir}/src \
  -I ${srcdir}/src/p44maintd_common \
  -D DISABLE_I2C=1 \
  -D DISABLE_SPI=1 \
  ${BOOST_CPPFLAGS} \
  ${JSONC_CFLAGS} \
  ${PTHREAD_CFLAGS} \
  ${p44maintd_EXTRACFLAGS} \
  ${p44maintd_PLATFORM} \
  ${p44maintd_VERSION} \
  ${p44maintd_DEBUG}


noinst_HEADERS = \
  src/p44maintd_common/p44maintd.cpp


p44maintd_SOURCES = \
  src/p44utils/application.cpp \
  src/p44utils/application.hpp \
  src/p44utils/consolekey.cpp \
  src/p44utils/consolekey.hpp \
  src/p44utils/digitalio.cpp \
  src/p44utils/digitalio.hpp \
  src/p44utils/error.cpp \
  src/p44utils/error.hpp \
  src/p44utils/extutils.cpp \
  src/p44utils/extutils.hpp \
  src/p44utils/fnv.cpp \
  src/p44utils/fnv.hpp \
  src/p44utils/crc32.cpp \
  src/p44utils/crc32.hpp \
  src/p44utils/fdcomm.cpp \
  src/p44utils/fdcomm.hpp \
  src/p44utils/gpio.cpp \
  src/p44utils/gpio.h \
  src/p44utils/gpio.hpp \
  src/p44utils/iopin.cpp \
  src/p44utils/iopin.hpp \
  src/p44utils/jsonobject.cpp \
  src/p44utils/jsonobject.hpp \
  src/p44utils/logger.cpp \
  src/p44utils/logger.hpp \
  src/p44utils/macaddress.cpp \
  src/p44utils/macaddress.hpp \
  src/p44utils/mainloop.cpp \
  src/p44utils/mainloop.hpp \
  src/p44utils/p44obj.cpp \
  src/p44utils/p44obj.hpp \
  src/p44utils/utils.cpp \
  src/p44utils/utils.hpp \
  src/p44utils/p44utils_common.hpp \
  src/p44utils_config.hpp \
  src/main.cpp

