// command.h
// Copyright (C) 2020 Spectre Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>
#include <memory>
#include <map>

#include "object.h"
#include "internal_types.h"

// maybe toss this into a spectre::command namespace?

namespace spectre {

enum class CommandID {
  kSetPosition,
  kGetPosition,
  kSetRotation,
  kGetRotation,
  kUpdatePhysics
};

class BaseCommand {
 protected:
  BaseCommand(ObjectID target_id, CommandID command_id) : target_id_(target_id), command_id_(command_id) {};
 public:
  ObjectID target_id_;
  CommandID command_id_;
};

class BasePositionCommand : public BaseCommand {
 protected:
  BasePositionCommand(ObjectID target_id, CommandID command_id, float x = 0.0f, float y = 0.0f, float z = 0.0f) : BaseCommand(target_id, command_id), x_(x), y_(y), z_(z) {};
 public:
  float x_;
  float y_;
  float z_;
};

class BaseRotationCommand : public BaseCommand {
  protected:
    BaseRotationCommand(ObjectID target_id, CommandID command_id, float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f) : BaseCommand(target_id, command_id), x_(x), y_(y), z_(z), w_(w) {};
  public:
    float x_;
    float y_;
    float z_;
    float w_;
};

class BasePhysicsUpdate : public BaseCommand {
protected:
  BasePhysicsUpdate(ObjectID target_id, CommandID command_id, Vector3 vector, Quaternion quaternion) : BaseCommand(target_id, command_id), vector_(vector), quaternion_(quaternion) {};
public:
  Vector3 vector_;
  Quaternion quaternion_;
};

class SetPosition : public BasePositionCommand {
 public:
  SetPosition(ObjectID target_id, float x, float y, float z) : BasePositionCommand(target_id, CommandID::kSetPosition, x, y, z) {};
};

class GetPosition : public BasePositionCommand {
 public:
  GetPosition(ObjectID target_id, float x, float y, float z) : BasePositionCommand(target_id, CommandID::kGetPosition, x, y, z) {};
};


class SetRotation : public BaseRotationCommand {
public:
  SetRotation(ObjectID target_id, float x, float y, float z, float w) : BaseRotationCommand(target_id, CommandID::kSetRotation, x, y, z, w) {};
};

class GetRotation : public BaseRotationCommand {
public:
  GetRotation(ObjectID target_id, float x, float y, float z, float w) : BaseRotationCommand(target_id, CommandID::kGetRotation, x, y, z, w) {};
};

class UpdatePhysics : public BasePhysicsUpdate {
public:
  UpdatePhysics(ObjectID target_id, Vector3 vector, Quaternion quaternion) : BasePhysicsUpdate(target_id, CommandID::kUpdatePhysics, vector, quaternion) {};
};

} // namespace spectre

#endif // COMMAND_H_