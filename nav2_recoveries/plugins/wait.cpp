// Copyright (c) 2019 Samsung Research America
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cmath>
#include <chrono>
#include <memory>

#include "wait.hpp"

namespace nav2_recoveries
{

Wait::Wait()
: Recovery<WaitAction>()
{
  duration_.sec = 0.0;
}

Wait::~Wait()
{
}

Status Wait::onRun(const std::shared_ptr<const WaitAction::Goal> command)
{
  duration_ = command->time;
  return Status::SUCCEEDED;
}

Status Wait::onCycleUpdate()
{
  rclcpp::sleep_for(
    rclcpp::Duration(duration_).to_chrono<std::chrono::nanoseconds>());
  return Status::SUCCEEDED;
}

}  // namespace nav2_recoveries

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(nav2_recoveries::Wait, nav2_core::Recovery)
