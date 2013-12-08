// Copyright 2012 Peter Kvitek.
//
// Author: Peter Kvitek (pete@kvitek.com)
// Based on app code by Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Settings app.

#ifndef MIDIPAL_APPS_SETTINGS_H_
#define MIDIPAL_APPS_SETTINGS_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

class Settings {
 public:
  Settings() { }

  static void OnInit();
  static void OnRawByte(uint8_t byte);
 
  static const prog_AppInfo app_info_;
 
  static uint8_t filter_active_sensing() { return filter_active_sensing_; }
  static uint16_t encoder_hold_threshold();

 private:
  static uint8_t filter_active_sensing_;
  static uint8_t encoder_hold_threshold_;
  
  DISALLOW_COPY_AND_ASSIGN(Settings);
};

} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_SETTINGS_H_