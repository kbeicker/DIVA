/*ckwg +29
* Copyright 2017 by Kitware, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  * Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  * Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  * Neither name of Kitware, Inc. nor the names of any contributors may be used
*    to endorse or promote products derived from this software without specific
*    prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once
#include <iostream>
#include <vector>
#include <utils/diva_utils_export.h>

enum class diva_source
{
  truth = 0
};

enum class diva_occlusion
{
  medium = 0,
  heavy
};

enum class diva_evaluation
{
  true_positive = 0,
  false_positive,
  false_alarm
};

enum class diva_keyframe
{
  yes = 0,
  no
};

class DIVA_UTILS_EXPORT diva_packet
{
public:
  diva_packet() {};
  virtual ~diva_packet() {};

  virtual void clear() = 0;
  virtual bool is_valid() const = 0;

  virtual void write(std::ostream& os) const = 0;
};

class DIVA_UTILS_EXPORT diva_meta :  public diva_packet
{
public:
  diva_meta();
  diva_meta(const std::string& msg);
  virtual ~diva_meta();

  void clear();
  bool is_valid() const;

  bool has_msg() const;
  std::string get_msg() const;
  void set_msg(const std::string& msg);
  void remove_msg();

  void write(std::ostream& os) const;

private:
  std::string _msg;
};
