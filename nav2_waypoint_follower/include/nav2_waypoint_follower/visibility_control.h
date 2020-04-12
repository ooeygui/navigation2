// Copyright 2020 Microsoft Corporation.
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

#ifndef NAV2_WAYPOINT_FOLLOWER__VISIBILITY_CONTROL_H_
#define NAV2_WAYPOINT_FOLLOWER__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define NAV2_WAYPOINT_FOLLOWER_EXPORT __attribute__ ((dllexport))
    #define NAV2_WAYPOINT_FOLLOWER_IMPORT __attribute__ ((dllimport))
  #else
    #define NAV2_WAYPOINT_FOLLOWER_EXPORT __declspec(dllexport)
    #define NAV2_WAYPOINT_FOLLOWER_IMPORT __declspec(dllimport)
  #endif
  #ifdef NAV2_WAYPOINT_FOLLOWER_BUILDING_DLL
    #define NAV2_WAYPOINT_FOLLOWER_PUBLIC NAV2_WAYPOINT_FOLLOWER_EXPORT
  #else
    #define NAV2_WAYPOINT_FOLLOWER_PUBLIC NAV2_WAYPOINT_FOLLOWER_IMPORT
  #endif
  #define NAV2_WAYPOINT_FOLLOWER_PUBLIC_TYPE NAV2_WAYPOINT_FOLLOWER_PUBLIC
  #define NAV2_WAYPOINT_FOLLOWER_LOCAL
#else
  #define NAV2_WAYPOINT_FOLLOWER_EXPORT __attribute__ ((visibility("default")))
  #define NAV2_WAYPOINT_FOLLOWER_IMPORT
  #if __GNUC__ >= 4
    #define NAV2_WAYPOINT_FOLLOWER_PUBLIC __attribute__ ((visibility("default")))
    #define NAV2_WAYPOINT_FOLLOWER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define NAV2_WAYPOINT_FOLLOWER_PUBLIC
    #define NAV2_WAYPOINT_FOLLOWER_LOCAL
  #endif
  #define NAV2_WAYPOINT_FOLLOWER_PUBLIC_TYPE
#endif

#endif  // NAV2_WAYPOINT_FOLLOWER__VISIBILITY_CONTROL_H_