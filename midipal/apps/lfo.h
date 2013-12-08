// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
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
// CC LFO app.

#ifndef MIDIPAL_APPS_LFO_H_
#define MIDIPAL_APPS_LFO_H_

#include "midipal/app.h"

namespace midipal { namespace apps {

enum LfoSyncMode
{
  LFO_SYNC_FREE_RUNNING,
  LFO_SYNC_NOTE_ON,
  LFO_SYNC_START
};

struct LfoData
{
  uint8_t midi_ch;
  uint8_t cc_number;
  uint8_t amount;
  uint8_t center_value;
  uint8_t waveform;
  uint8_t cycle_duration;
  uint8_t sync_mode;
};

const uint8_t kNumLfos = 6;

class Lfo
{
 public:

  Lfo() {}

  static void OnInit();
  static void OnRawMidiData(
     uint8_t status,
     uint8_t* data,
     uint8_t data_size,
     uint8_t accepted_channel);

  static void OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity);
  static void OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity);
  
  static void OnInternalClockTick();
  static void OnContinue();
  static void OnStart();
  static void OnStop();
  static void OnClock();
  
  static void SetParameter(uint8_t key, uint8_t value);
  
  //static const prog_AppInfo app_info_;

 protected:

  static void Stop();
  static void Start();
  static void Tick();
  
  static uint8_t running_;
  static uint8_t clk_mode_;
  static uint8_t bpm_;
  static uint8_t groove_template_;
  static uint8_t groove_amount_;
  static uint8_t clock_division_;  
  //static uint8_t channel_;
  
  static LfoData lfo_data_[kNumLfos];

  static uint16_t phase_[kNumLfos];
  static uint16_t phase_increment_[kNumLfos];
  
  static uint8_t tick_;
  static uint8_t midi_clock_prescaler_;
  
 private:
  DISALLOW_COPY_AND_ASSIGN(Lfo);
};

// ----------------------------------------------------------------------------

class Lfo1 : public Lfo
{
public:
  Lfo1() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo1);

};

// ----------------------------------------------------------------------------

class Lfo2 : public Lfo
{
public:
  Lfo2() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo2);
};

// ----------------------------------------------------------------------------

class Lfo3 : public Lfo
{
public:
  Lfo3() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo3);
};

// ----------------------------------------------------------------------------

class Lfo4 : public Lfo
{
public:
  Lfo4() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo4);
};

// ----------------------------------------------------------------------------

class Lfo5 : public Lfo
{
public:
  Lfo5() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo5);
};

// ----------------------------------------------------------------------------

class Lfo6 : public Lfo
{
public:
  Lfo6() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo6);
};

// ----------------------------------------------------------------------------

class Lfo7 : public Lfo
{
public:
  Lfo7() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo7);
};

// ----------------------------------------------------------------------------

class Lfo8 : public Lfo
{
public:
  Lfo8() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo8);
};

// ----------------------------------------------------------------------------

class Lfo9 : public Lfo
{
public:
    Lfo9() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo9);
};

// ----------------------------------------------------------------------------

class Lfo10 : public Lfo
{
public:
    Lfo10() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo10);
};

// ----------------------------------------------------------------------------

class Lfo11 : public Lfo
{
public:
    Lfo11() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo11);
};

// ----------------------------------------------------------------------------

class Lfo12 : public Lfo
{
public:
    Lfo12() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo12);
};

// ----------------------------------------------------------------------------

class Lfo13 : public Lfo
{
public:
    Lfo13() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo13);
};

// ----------------------------------------------------------------------------

class Lfo14 : public Lfo
{
public:
    Lfo14() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo14);
};

// ----------------------------------------------------------------------------

class Lfo15 : public Lfo
{
public:
    Lfo15() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo15);
};

// ----------------------------------------------------------------------------

class Lfo16 : public Lfo
{
public:
  Lfo16() {}
  static const prog_AppInfo app_info_;

private:
 DISALLOW_COPY_AND_ASSIGN(Lfo16);
};


} }  // namespace midipal::apps

#endif // MIDIPAL_APPS_LFO_H_
