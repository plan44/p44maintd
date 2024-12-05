//  SPDX-License-Identifier: GPL-3.0-or-later
//
//  Copyright (c) 2024 plan44.ch / Lukas Zeller, Zurich, Switzerland
//
//  Author: Lukas Zeller <luz@plan44.ch>
//
//  This file is part of p44utils.
//
//  p44utils is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  p44utils is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with p44utils. If not, see <http://www.gnu.org/licenses/>.
//

// determine build environment
#if P44_BUILD_OW
  // OpenWRT based products, possibly on different platforms
  #define BUILDENV_OPENWRT 1
#elif defined(__APPLE__)
  // pseudo-Platform for debugging with XCode
  #define BUILDENV_XCODE 1
#else
  #define BUILDENV_GENERIC 1
  #warning "Unknown build environment - use generic linux settings"
#endif

#if BUILDENV_XCODE || BUILDENV_GENERIC
  // dummy for test on OS X and generic Linux
  #undef FLASH_PATH
  #define FLASH_PATH "/tmp/"
#endif

// the basic application class
#include "p44maintd.cpp"


int main(int argc, char **argv)
{
  // prevent all logging until command line determines level
  SETLOGLEVEL(LOG_EMERG);
  SETERRLEVEL(LOG_EMERG, false); // messages, if any, go to stderr
  // create app with current mainloop
  Application *application = NULL;
  application = new(P44maintd);
  // pass control
  int status = application->main(argc, argv);
  // done
  delete application;
  return status;
}
