// transform_component.h
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

#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

#include <memory>
#include <memory>
#include <iostream>

#include "command.h"
#include "logger.h"
#include "world.h"
#include "component.h"
#include "internal_types.h"

#include "../third_party/bullet3/src/btBulletDynamicsCommon.h"
#include "../third_party/bullet3/src/Bullet3Serialize/Bullet2FileLoader/b3BulletFile.h"

namespace spectre {

class BaseCommand;

class TransformComponent : public Component {
 public:
  void Start();
  void Update(float delta_time);
  bool ExecuteCommand(std::shared_ptr<BaseCommand> command, std::shared_ptr<Object> caller);
  ComponentID component_id_ = ComponentID::kTransform;
  Vector3 pos = Vector3();
  Quaternion rot = Quaternion();
};

} // namespace spectre

#endif // TRANSFORM_COMPONENT_H_
