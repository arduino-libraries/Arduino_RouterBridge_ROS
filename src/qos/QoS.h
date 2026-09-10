/*
This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_QOS_H
#define ROUTERBRIDGE_ROS_QOS_H
#include <stdint.h>
#include <MsgPack.h>

namespace ros2ino {

        enum class HistoryPolicy
        {
            KeepLast = 10, // RMW_QOS_POLICY_HISTORY_KEEP_LAST,
            KeepAll = 20, // RMW_QOS_POLICY_HISTORY_KEEP_ALL,
            SystemDefault = 30, // RMW_QOS_POLICY_HISTORY_SYSTEM_DEFAULT,
            Unknown = 40, // RMW_QOS_POLICY_HISTORY_UNKNOWN,
          };

        enum class ReliabilityPolicy
        {
            BestEffort = 10, // RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT,
            Reliable = 20, // RMW_QOS_POLICY_RELIABILITY_RELIABLE,
            SystemDefault = 30, // RMW_QOS_POLICY_RELIABILITY_SYSTEM_DEFAULT,
            BestAvailable = 40, // RMW_QOS_POLICY_RELIABILITY_BEST_AVAILABLE,
            Unknown = 50, // RMW_QOS_POLICY_RELIABILITY_UNKNOWN,
          };

        enum class DurabilityPolicy
        {
            Volatile = 10, // RMW_QOS_POLICY_DURABILITY_VOLATILE,
            TransientLocal = 20, // RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL,
            SystemDefault = 30, // RMW_QOS_POLICY_DURABILITY_SYSTEM_DEFAULT,
            BestAvailable = 40, // RMW_QOS_POLICY_DURABILITY_BEST_AVAILABLE,
            Unknown = 50, // RMW_QOS_POLICY_DURABILITY_UNKNOWN,
          };

        struct QoS {

            MsgPack::str_t _history_key = "history";
            int _history = (int)HistoryPolicy::KeepLast;

            MsgPack::str_t _depth_key = "depth";
            uint64_t _depth = 10;

            MsgPack::str_t _reliability_key = "reliability";
            int _reliability = (int)ReliabilityPolicy::Reliable;

            MsgPack::str_t _durability_key = "durability";
            int _durability = (int)DurabilityPolicy::Volatile;

            QoS() = default;

            QoS(uint64_t depth): _depth(depth) {}

            QoS(HistoryPolicy history, uint64_t depth,
                ReliabilityPolicy reliability = ReliabilityPolicy::Reliable,
                DurabilityPolicy durability = DurabilityPolicy::Volatile):
                _history((int)history), _depth(depth),
                _reliability((int)reliability), _durability((int)durability) {}

            // history
            QoS& history(HistoryPolicy history) { _history = (int)history; return *this; }
            HistoryPolicy history() const { return (HistoryPolicy)_history; }

            QoS& keep_last(uint64_t depth) { _history = (int)HistoryPolicy::KeepLast; _depth = depth; return *this; }
            QoS& keep_all() { _history = (int)HistoryPolicy::KeepAll; return *this; }

            // depth
            QoS& depth(uint64_t depth) { _depth = depth; return *this; }
            uint64_t depth() const { return _depth; }

            // reliability
            QoS& reliability(ReliabilityPolicy reliability) { _reliability = (int)reliability; return *this; }
            ReliabilityPolicy reliability() const { return (ReliabilityPolicy)_reliability; }

            QoS& reliable() { _reliability = (int)ReliabilityPolicy::Reliable; return *this; }
            QoS& best_effort() { _reliability = (int)ReliabilityPolicy::BestEffort; return *this; }

            // durability
            QoS& durability(DurabilityPolicy durability) { _durability = (int)durability; return *this; }
            DurabilityPolicy durability() const { return (DurabilityPolicy)_durability; }

            QoS& durability_volatile() { _durability = (int)DurabilityPolicy::Volatile; return *this; }
            QoS& transient_local() { _durability = (int)DurabilityPolicy::TransientLocal; return *this; }

            MSGPACK_DEFINE_MAP(_history_key, _history, _depth_key, _depth, _reliability_key, _reliability, _durability_key, _durability);

        };

} // namespace ros2ino

#endif //ROUTERBRIDGE_ROS_QOS_H