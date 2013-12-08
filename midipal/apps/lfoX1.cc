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

#include "midipal/apps/lfo.h"

#include "avrlib/op.h"
#include "avrlib/random.h"

#include "midipal/clock.h"
#include "midipal/note_stack.h"
#include "midipal/ui.h"

namespace midipal { namespace apps {

using namespace avrlib;

const prog_uint8_t lfo_factory_data[48] PROGMEM =
{
  0, 0, 120, 0, 0, 16,

  0, 7, 63, 63, 0, 2, 0,
  1, 10, 0, 63, 0, 4, 0,
  2, 74, 0, 63, 0, 2, 0,
  3, 71, 0, 63, 0, 4, 0,
  /**/
  4, 7, 63, 63, 0, 2, 0,
  5, 10, 0, 63, 0, 4, 0,
  //6, 74, 0, 63, 0, 2, 0,
  //3, 71, 0, 63, 0, 4, 0,
  /**/
};

/* <static> */
uint8_t Lfo::running_;
uint8_t Lfo::clk_mode_;
uint8_t Lfo::bpm_;
uint8_t Lfo::groove_template_;
uint8_t Lfo::groove_amount_;
uint8_t Lfo::clock_division_;  
//uint8_t Lfo::channel_;

LfoData Lfo::lfo_data_[kNumLfos];

uint16_t Lfo::phase_[kNumLfos];
uint16_t Lfo::phase_increment_[kNumLfos];

uint8_t Lfo::tick_;
uint8_t Lfo::midi_clock_prescaler_;
/* </static> */


/* static */
/*
const prog_AppInfo Lfo1::app_info_ PROGMEM =
{
  &OnInit, // void (*OnInit)();
  &OnNoteOn, // void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);
  &OnNoteOff, // void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);
  NULL, NULL, NULL, NULL, NULL, NULL,
  &OnClock, // void (*OnClock)();
  &OnStart, // void (*OnStart)();
  &OnContinue, // void (*OnContinue)();
  &OnStop, // void (*OnStop)();
  NULL, NULL,
  &OnRawMidiData, // void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t);
  &OnInternalClockTick, // void (*OnInternalClockTick)();
  NULL, NULL, NULL, NULL, NULL, NULL,
  &SetParameter, // void (*SetParameter)(uint8_t, uint8_t);
  NULL, NULL,
  6 + sizeof(LfoData) * kNumLfos, // settings_size
  SETTINGS_LFO1, // settings_offset
  &running_, // settings_data
  lfo_factory_data, // factory_data
  STR_RES_CC_LFO_1, // app_name
  true
};
*/

#define LFO_APP_INFOS(i, AppNameID) \
{ \
  &OnInit, /*void (*OnInit)();*/ \
  &OnNoteOn, /*void (*OnNoteOn)(uint8_t, uint8_t, uint8_t);*/ \
  &OnNoteOff, /* void (*OnNoteOff)(uint8_t, uint8_t, uint8_t);*/ \
  NULL, NULL, NULL, NULL, NULL, NULL, \
  &OnClock, /* void (*OnClock)(); */ \
  &OnStart, /* void (*OnStart)(); */ \
  &OnContinue, /* void (*OnContinue)(); */ \
  &OnStop, /* void (*OnStop)(); */ \
  NULL, NULL, \
  &OnRawMidiData, /* void (*OnRawMidiData)(uint8_t, uint8_t*, uint8_t, uint8_t); */ \
  &OnInternalClockTick, /* void (*OnInternalClockTick)(); */ \
  NULL, NULL, NULL, NULL, NULL, NULL, \
  &SetParameter, /* void (*SetParameter)(uint8_t, uint8_t); */ \
  NULL, NULL, \
  6 + sizeof(LfoData) * kNumLfos, /* settings_size */ \
  SETTINGS_LFO1 + (i * 64), /* settings_offset */ \
  &running_, /* settings_data */ \
  lfo_factory_data, /* factory_data */ \
  AppNameID, /* app_name */ \
  true \
};


const prog_AppInfo Lfo1::app_info_ PROGMEM = LFO_APP_INFOS(0, STR_RES_CC_LFO_1)
const prog_AppInfo Lfo2::app_info_ PROGMEM = LFO_APP_INFOS(1, STR_RES_CC_LFO_2)
const prog_AppInfo Lfo3::app_info_ PROGMEM = LFO_APP_INFOS(2, STR_RES_CC_LFO_3)
const prog_AppInfo Lfo4::app_info_ PROGMEM = LFO_APP_INFOS(3, STR_RES_CC_LFO_4)
const prog_AppInfo Lfo5::app_info_ PROGMEM = LFO_APP_INFOS(4, STR_RES_CC_LFO_5)
const prog_AppInfo Lfo6::app_info_ PROGMEM = LFO_APP_INFOS(5, STR_RES_CC_LFO_6)
const prog_AppInfo Lfo7::app_info_ PROGMEM = LFO_APP_INFOS(6, STR_RES_CC_LFO_7)
const prog_AppInfo Lfo8::app_info_ PROGMEM = LFO_APP_INFOS(7, STR_RES_CC_LFO_8)
const prog_AppInfo Lfo9::app_info_ PROGMEM = LFO_APP_INFOS(8, STR_RES_CC_LFO_9)
const prog_AppInfo Lfo10::app_info_ PROGMEM = LFO_APP_INFOS(9, STR_RES_CC_LFO10)
const prog_AppInfo Lfo11::app_info_ PROGMEM = LFO_APP_INFOS(10, STR_RES_CC_LFO11)
const prog_AppInfo Lfo12::app_info_ PROGMEM = LFO_APP_INFOS(11, STR_RES_CC_LFO12)
const prog_AppInfo Lfo13::app_info_ PROGMEM = LFO_APP_INFOS(12, STR_RES_CC_LFO13)
const prog_AppInfo Lfo14::app_info_ PROGMEM = LFO_APP_INFOS(13, STR_RES_CC_LFO14)
const prog_AppInfo Lfo15::app_info_ PROGMEM = LFO_APP_INFOS(14, STR_RES_CC_LFO15)
const prog_AppInfo Lfo16::app_info_ PROGMEM = LFO_APP_INFOS(15, STR_RES_CC_LFO16)

/* static */
void Lfo::OnInit()
{
  ui.AddPage(STR_RES_RUN, STR_RES_OFF, 0, 1);   // 1
  ui.AddClockPages();                           // 2 - 5 param
  ui.AddPage(STR_RES_RES, STR_RES_2_1, 0, 16);  // 6
  //ui.AddPage(STR_RES_CHN, UNIT_INDEX, 0, 16);

  for (uint8_t i = 0; i < kNumLfos; ++i)
  {
    // todo?: ui.AddPage(STR_RES_CHN, UNIT_INTEGER_ALL, 0, 16);
    //ui.AddPage(STR_RES_CHN1 + i, UNIT_INDEX, 0, 16); // UNIT_CHANNEL
    ui.AddPage(STR_RES_CH1 + i, UNIT_INDEX, 0, 16);
    ui.AddPage(STR_RES_CC1 + i, UNIT_INTEGER, 0, 127);
    ui.AddPage(STR_RES_AM1 + i, UNIT_SIGNED_INTEGER, -63, 63);
    ui.AddPage(STR_RES_CE1 + i, UNIT_INTEGER, 0, 127);
    ui.AddPage(STR_RES_WF1 + i, STR_RES_TRI, 0, 17);
    ui.AddPage(STR_RES_RT1 + i, STR_RES_128, 0, 47);
    ui.AddPage(STR_RES_SY1 + i, STR_RES_FRE, 0, 2);
  }

  clock.Update(bpm_, groove_template_, groove_amount_);
  SetParameter(2, bpm_);
  clock.Start();
  running_ = 0;
}

/* static */
void Lfo::OnRawMidiData(
   uint8_t status,
   uint8_t* data,
   uint8_t data_size,
   uint8_t accepted_channel)
{
  app.Send(status, data, data_size);
}

/* static */
void Lfo::SetParameter(uint8_t key, uint8_t value)
{
  if (key == 0)
  {
    if (value == 1)
    {
      Start();
    }
    else
    {
      Stop();
    }
  }

  static_cast<uint8_t*>(&running_)[key] = value;

  if (key < 5)
  {
    clock.Update(bpm_, groove_template_, groove_amount_);
  }

  midi_clock_prescaler_ = ResourcesManager::Lookup<uint8_t, uint8_t>(
      midi_clock_tick_per_step, clock_division_);

  uint16_t factor = midi_clock_prescaler_;

  for (uint8_t i = 0; i < kNumLfos; ++i)
  {
    phase_increment_[i] = ResourcesManager::Lookup<uint16_t, uint8_t>(
      lut_res_increments, lfo_data_[i].cycle_duration) * factor;
  }
}

/* static */
void Lfo::OnStart() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Start();
  }
}

/* static */
void Lfo::OnStop() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    Stop();
  }
}

/* static */
void Lfo::OnContinue() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL) {
    running_ = 1;
  }
}

/* static */
void Lfo::OnClock() {
  if (clk_mode_ == CLOCK_MODE_EXTERNAL && running_) {
    Tick();
  }
}

/* static */
void Lfo::OnInternalClockTick() {
  if (clk_mode_ == CLOCK_MODE_INTERNAL && running_) {
    app.SendNow(0xf8);
    Tick();
  }
}

/* static */
void Lfo::OnNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
{
  /*if (channel != channel_ && channel <= 15)
  {
    return;
  }*/

  for (uint8_t i = 0; i < kNumLfos; ++i)
  {
    if (lfo_data_[i].midi_ch != channel && channel <= 15)
    {
      continue;
    }

    if (lfo_data_[i].sync_mode == LFO_SYNC_NOTE_ON ||
        (lfo_data_[i].sync_mode == LFO_SYNC_START && note_stack.size() == 0))
    {
      phase_[i] = 0;
    }
  }

  note_stack.NoteOn(note, velocity);
}

/* static */
void Lfo::OnNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
{
  /*if (channel != channel_ && channel <= 15)
  {
    return;
  }*/

  for (uint8_t i = 0; i < kNumLfos; ++i)
  {
      if (channel == lfo_data_[i].midi_ch || lfo_data_[i].midi_ch > 15)
      {
        note_stack.NoteOff(note);
        break;
      }
  }
}

/* static */
void Lfo::Stop()
{
  if (!running_)
  {
    return;
  }

  if (clk_mode_ == CLOCK_MODE_INTERNAL)
  {
    app.SendNow(0xfc);
  }

  running_ = 0;
}

/* static */
void Lfo::Start()
{
  if (running_)
  {
    return;
  }

  if (clk_mode_ == CLOCK_MODE_INTERNAL)
  {
    clock.Start();
    app.SendNow(0xfa);
  }

  tick_ = midi_clock_prescaler_ - 1;
  running_ = 1;
  for (uint8_t i = 0; i < kNumLfos; ++i)
  {
    phase_[i] = 0;
  }
}

/* static */
void Lfo::Tick()
{
  ++tick_;
  if (tick_ >= midi_clock_prescaler_)
  {
    tick_ = 0;
    for (uint8_t i = 0; i < kNumLfos; ++i)
    {
      uint8_t value;
      uint8_t skip = 0;

      if (lfo_data_[i].waveform == 17)
      {
        if (phase_[i] < phase_increment_[i])
        {
          value = Random::GetByte();
        }
        else
        {
          skip = 1;
        }
      }
      else
      {
        uint16_t offset = U8U8Mul(lfo_data_[i].waveform, 129);
        value = InterpolateSample(wav_res_lfo_waveforms + offset, phase_[i] >> 1);
      }

      phase_[i] += phase_increment_[i];

      if (lfo_data_[i].amount && !skip)
      {
        int16_t scaled_value = static_cast<int16_t>(lfo_data_[i].center_value) +
            S8S8MulShift8(lfo_data_[i].amount << 1, value - 128);

        scaled_value = Clip(scaled_value, 0, 127);

        uint8_t ccNum = lfo_data_[i].cc_number & 0x7f;
        uint8_t val = scaled_value & 0x7f;

        if (lfo_data_[i].midi_ch > 15)
        {
          for(uint8_t i = 0; i < 16; ++i)
          {
            app.Send3(0xb0 | i, lfo_data_[i].cc_number & 0x7f, scaled_value & 0x7f);
          }
        }
        else
        {
          app.Send3(0xb0 | lfo_data_[i].midi_ch, lfo_data_[i].cc_number & 0x7f, scaled_value & 0x7f);
        }

        //app.Send3(0xb0 | channel_, lfo_data_[i].cc_number & 0x7f, scaled_value & 0x7f);
      }
    }
  }
}

}

}  // namespace midipal::apps
