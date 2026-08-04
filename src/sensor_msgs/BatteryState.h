/*
    This file is part of the Arduino_RouterBridge_ROS library.

    Copyright (c) Arduino s.r.l. and/or its affiliated companies

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

*/

#ifndef ROUTERBRIDGE_ROS_SENSOR_MSGS_BATTERYSTATE_H
#define ROUTERBRIDGE_ROS_SENSOR_MSGS_BATTERYSTATE_H
#include <MsgPack.h>

#include "../std_msgs/Header.h"

#define ROUTERBRIDGE_ROS_SENSOR_MSGS_BATTERYSTATE "sensor_msgs/msg/BatteryState"

namespace sensor_msgs {

namespace msg {

    struct BatteryState {
        static constexpr const char* _type = ROUTERBRIDGE_ROS_SENSOR_MSGS_BATTERYSTATE;

        MsgPack::str_t key1 = "POWER_SUPPLY_STATUS_UNKNOWN";
        uint8_t POWER_SUPPLY_STATUS_UNKNOWN;

        MsgPack::str_t key2 = "POWER_SUPPLY_STATUS_CHARGING";
        uint8_t POWER_SUPPLY_STATUS_CHARGING;

        MsgPack::str_t key3 = "POWER_SUPPLY_STATUS_DISCHARGING";
        uint8_t POWER_SUPPLY_STATUS_DISCHARGING;

        MsgPack::str_t key4 = "POWER_SUPPLY_STATUS_NOT_CHARGING";
        uint8_t POWER_SUPPLY_STATUS_NOT_CHARGING;

        MsgPack::str_t key5 = "POWER_SUPPLY_STATUS_FULL";
        uint8_t POWER_SUPPLY_STATUS_FULL;

        MsgPack::str_t key6 = "POWER_SUPPLY_HEALTH_UNKNOWN";
        uint8_t POWER_SUPPLY_HEALTH_UNKNOWN;

        MsgPack::str_t key7 = "POWER_SUPPLY_HEALTH_GOOD";
        uint8_t POWER_SUPPLY_HEALTH_GOOD;

        MsgPack::str_t key8 = "POWER_SUPPLY_HEALTH_OVERHEAT";
        uint8_t POWER_SUPPLY_HEALTH_OVERHEAT;

        MsgPack::str_t key9 = "POWER_SUPPLY_HEALTH_DEAD";
        uint8_t POWER_SUPPLY_HEALTH_DEAD;

        MsgPack::str_t key10 = "POWER_SUPPLY_HEALTH_OVERVOLTAGE";
        uint8_t POWER_SUPPLY_HEALTH_OVERVOLTAGE;

        MsgPack::str_t key11 = "POWER_SUPPLY_HEALTH_UNSPEC_FAILURE";
        uint8_t POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;

        MsgPack::str_t key12 = "POWER_SUPPLY_HEALTH_COLD";
        uint8_t POWER_SUPPLY_HEALTH_COLD;

        MsgPack::str_t key13 = "POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE";
        uint8_t POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE;

        MsgPack::str_t key14 = "POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE";
        uint8_t POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;

        MsgPack::str_t key15 = "POWER_SUPPLY_TECHNOLOGY_UNKNOWN";
        uint8_t POWER_SUPPLY_TECHNOLOGY_UNKNOWN;

        MsgPack::str_t key16 = "POWER_SUPPLY_TECHNOLOGY_NIMH";
        uint8_t POWER_SUPPLY_TECHNOLOGY_NIMH;

        MsgPack::str_t key17 = "POWER_SUPPLY_TECHNOLOGY_LION";
        uint8_t POWER_SUPPLY_TECHNOLOGY_LION;

        MsgPack::str_t key18 = "POWER_SUPPLY_TECHNOLOGY_LIPO";
        uint8_t POWER_SUPPLY_TECHNOLOGY_LIPO;

        MsgPack::str_t key19 = "POWER_SUPPLY_TECHNOLOGY_LIFE";
        uint8_t POWER_SUPPLY_TECHNOLOGY_LIFE;

        MsgPack::str_t key20 = "POWER_SUPPLY_TECHNOLOGY_NICD";
        uint8_t POWER_SUPPLY_TECHNOLOGY_NICD;

        MsgPack::str_t key21 = "POWER_SUPPLY_TECHNOLOGY_LIMN";
        uint8_t POWER_SUPPLY_TECHNOLOGY_LIMN;

        MsgPack::str_t key22 = "POWER_SUPPLY_TECHNOLOGY_TERNARY";
        uint8_t POWER_SUPPLY_TECHNOLOGY_TERNARY;

        MsgPack::str_t key23 = "POWER_SUPPLY_TECHNOLOGY_VRLA";
        uint8_t POWER_SUPPLY_TECHNOLOGY_VRLA;

        MsgPack::str_t key24 = "header";
        std_msgs::msg::Header header;

        MsgPack::str_t key25 = "voltage";
        float voltage;

        MsgPack::str_t key26 = "temperature";
        float temperature;

        MsgPack::str_t key27 = "current";
        float current;

        MsgPack::str_t key28 = "charge";
        float charge;

        MsgPack::str_t key29 = "capacity";
        float capacity;

        MsgPack::str_t key30 = "design_capacity";
        float design_capacity;

        MsgPack::str_t key31 = "percentage";
        float percentage;

        MsgPack::str_t key32 = "power_supply_status";
        uint8_t power_supply_status;

        MsgPack::str_t key33 = "power_supply_health";
        uint8_t power_supply_health;

        MsgPack::str_t key34 = "power_supply_technology";
        uint8_t power_supply_technology;

        MsgPack::str_t key35 = "present";
        bool present;

        MsgPack::str_t key36 = "cell_voltage";
        std::vector<float> cell_voltage;

        MsgPack::str_t key37 = "cell_temperature";
        std::vector<float> cell_temperature;

        MsgPack::str_t key38 = "location";
        MsgPack::str_t location;

        MsgPack::str_t key39 = "serial_number";
        MsgPack::str_t serial_number;

        BatteryState() = default;

        BatteryState(uint8_t power_supply_status_unknown, uint8_t power_supply_status_charging, uint8_t power_supply_status_discharging, uint8_t power_supply_status_not_charging, uint8_t power_supply_status_full, uint8_t power_supply_health_unknown, uint8_t power_supply_health_good, uint8_t power_supply_health_overheat, uint8_t power_supply_health_dead, uint8_t power_supply_health_overvoltage, uint8_t power_supply_health_unspec_failure, uint8_t power_supply_health_cold, uint8_t power_supply_health_watchdog_timer_expire, uint8_t power_supply_health_safety_timer_expire, uint8_t power_supply_technology_unknown, uint8_t power_supply_technology_nimh, uint8_t power_supply_technology_lion, uint8_t power_supply_technology_lipo, uint8_t power_supply_technology_life, uint8_t power_supply_technology_nicd, uint8_t power_supply_technology_limn, uint8_t power_supply_technology_ternary, uint8_t power_supply_technology_vrla, std_msgs::msg::Header header, float voltage, float temperature, float current, float charge, float capacity, float design_capacity, float percentage, uint8_t power_supply_status, uint8_t power_supply_health, uint8_t power_supply_technology, bool present, std::vector<float> cell_voltage, std::vector<float> cell_temperature, MsgPack::str_t location, MsgPack::str_t serial_number): POWER_SUPPLY_STATUS_UNKNOWN(power_supply_status_unknown), POWER_SUPPLY_STATUS_CHARGING(power_supply_status_charging), POWER_SUPPLY_STATUS_DISCHARGING(power_supply_status_discharging), POWER_SUPPLY_STATUS_NOT_CHARGING(power_supply_status_not_charging), POWER_SUPPLY_STATUS_FULL(power_supply_status_full), POWER_SUPPLY_HEALTH_UNKNOWN(power_supply_health_unknown), POWER_SUPPLY_HEALTH_GOOD(power_supply_health_good), POWER_SUPPLY_HEALTH_OVERHEAT(power_supply_health_overheat), POWER_SUPPLY_HEALTH_DEAD(power_supply_health_dead), POWER_SUPPLY_HEALTH_OVERVOLTAGE(power_supply_health_overvoltage), POWER_SUPPLY_HEALTH_UNSPEC_FAILURE(power_supply_health_unspec_failure), POWER_SUPPLY_HEALTH_COLD(power_supply_health_cold), POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE(power_supply_health_watchdog_timer_expire), POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE(power_supply_health_safety_timer_expire), POWER_SUPPLY_TECHNOLOGY_UNKNOWN(power_supply_technology_unknown), POWER_SUPPLY_TECHNOLOGY_NIMH(power_supply_technology_nimh), POWER_SUPPLY_TECHNOLOGY_LION(power_supply_technology_lion), POWER_SUPPLY_TECHNOLOGY_LIPO(power_supply_technology_lipo), POWER_SUPPLY_TECHNOLOGY_LIFE(power_supply_technology_life), POWER_SUPPLY_TECHNOLOGY_NICD(power_supply_technology_nicd), POWER_SUPPLY_TECHNOLOGY_LIMN(power_supply_technology_limn), POWER_SUPPLY_TECHNOLOGY_TERNARY(power_supply_technology_ternary), POWER_SUPPLY_TECHNOLOGY_VRLA(power_supply_technology_vrla), header(header), voltage(voltage), temperature(temperature), current(current), charge(charge), capacity(capacity), design_capacity(design_capacity), percentage(percentage), power_supply_status(power_supply_status), power_supply_health(power_supply_health), power_supply_technology(power_supply_technology), present(present), cell_voltage(cell_voltage), cell_temperature(cell_temperature), location(location), serial_number(serial_number) {}

        MSGPACK_DEFINE_MAP(key1, POWER_SUPPLY_STATUS_UNKNOWN, key2, POWER_SUPPLY_STATUS_CHARGING, key3, POWER_SUPPLY_STATUS_DISCHARGING, key4, POWER_SUPPLY_STATUS_NOT_CHARGING, key5, POWER_SUPPLY_STATUS_FULL, key6, POWER_SUPPLY_HEALTH_UNKNOWN, key7, POWER_SUPPLY_HEALTH_GOOD, key8, POWER_SUPPLY_HEALTH_OVERHEAT, key9, POWER_SUPPLY_HEALTH_DEAD, key10, POWER_SUPPLY_HEALTH_OVERVOLTAGE, key11, POWER_SUPPLY_HEALTH_UNSPEC_FAILURE, key12, POWER_SUPPLY_HEALTH_COLD, key13, POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE, key14, POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE, key15, POWER_SUPPLY_TECHNOLOGY_UNKNOWN, key16, POWER_SUPPLY_TECHNOLOGY_NIMH, key17, POWER_SUPPLY_TECHNOLOGY_LION, key18, POWER_SUPPLY_TECHNOLOGY_LIPO, key19, POWER_SUPPLY_TECHNOLOGY_LIFE, key20, POWER_SUPPLY_TECHNOLOGY_NICD, key21, POWER_SUPPLY_TECHNOLOGY_LIMN, key22, POWER_SUPPLY_TECHNOLOGY_TERNARY, key23, POWER_SUPPLY_TECHNOLOGY_VRLA, key24, header, key25, voltage, key26, temperature, key27, current, key28, charge, key29, capacity, key30, design_capacity, key31, percentage, key32, power_supply_status, key33, power_supply_health, key34, power_supply_technology, key35, present, key36, cell_voltage, key37, cell_temperature, key38, location, key39, serial_number);

        bool operator==(const BatteryState& other) const { return this->POWER_SUPPLY_STATUS_UNKNOWN == other.POWER_SUPPLY_STATUS_UNKNOWN && this->POWER_SUPPLY_STATUS_CHARGING == other.POWER_SUPPLY_STATUS_CHARGING && this->POWER_SUPPLY_STATUS_DISCHARGING == other.POWER_SUPPLY_STATUS_DISCHARGING && this->POWER_SUPPLY_STATUS_NOT_CHARGING == other.POWER_SUPPLY_STATUS_NOT_CHARGING && this->POWER_SUPPLY_STATUS_FULL == other.POWER_SUPPLY_STATUS_FULL && this->POWER_SUPPLY_HEALTH_UNKNOWN == other.POWER_SUPPLY_HEALTH_UNKNOWN && this->POWER_SUPPLY_HEALTH_GOOD == other.POWER_SUPPLY_HEALTH_GOOD && this->POWER_SUPPLY_HEALTH_OVERHEAT == other.POWER_SUPPLY_HEALTH_OVERHEAT && this->POWER_SUPPLY_HEALTH_DEAD == other.POWER_SUPPLY_HEALTH_DEAD && this->POWER_SUPPLY_HEALTH_OVERVOLTAGE == other.POWER_SUPPLY_HEALTH_OVERVOLTAGE && this->POWER_SUPPLY_HEALTH_UNSPEC_FAILURE == other.POWER_SUPPLY_HEALTH_UNSPEC_FAILURE && this->POWER_SUPPLY_HEALTH_COLD == other.POWER_SUPPLY_HEALTH_COLD && this->POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE == other.POWER_SUPPLY_HEALTH_WATCHDOG_TIMER_EXPIRE && this->POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE == other.POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE && this->POWER_SUPPLY_TECHNOLOGY_UNKNOWN == other.POWER_SUPPLY_TECHNOLOGY_UNKNOWN && this->POWER_SUPPLY_TECHNOLOGY_NIMH == other.POWER_SUPPLY_TECHNOLOGY_NIMH && this->POWER_SUPPLY_TECHNOLOGY_LION == other.POWER_SUPPLY_TECHNOLOGY_LION && this->POWER_SUPPLY_TECHNOLOGY_LIPO == other.POWER_SUPPLY_TECHNOLOGY_LIPO && this->POWER_SUPPLY_TECHNOLOGY_LIFE == other.POWER_SUPPLY_TECHNOLOGY_LIFE && this->POWER_SUPPLY_TECHNOLOGY_NICD == other.POWER_SUPPLY_TECHNOLOGY_NICD && this->POWER_SUPPLY_TECHNOLOGY_LIMN == other.POWER_SUPPLY_TECHNOLOGY_LIMN && this->POWER_SUPPLY_TECHNOLOGY_TERNARY == other.POWER_SUPPLY_TECHNOLOGY_TERNARY && this->POWER_SUPPLY_TECHNOLOGY_VRLA == other.POWER_SUPPLY_TECHNOLOGY_VRLA && this->header == other.header && this->voltage == other.voltage && this->temperature == other.temperature && this->current == other.current && this->charge == other.charge && this->capacity == other.capacity && this->design_capacity == other.design_capacity && this->percentage == other.percentage && this->power_supply_status == other.power_supply_status && this->power_supply_health == other.power_supply_health && this->power_supply_technology == other.power_supply_technology && this->present == other.present && this->cell_voltage == other.cell_voltage && this->cell_temperature == other.cell_temperature && this->location == other.location && this->serial_number == other.serial_number; }
    };

} // namespace msg

} // namespace sensor_msgs
#endif //ROUTERBRIDGE_ROS_SENSOR_MSGS_BATTERYSTATE_H