/*----------------------------------------------------------------------------*/
/* Copyright (c) 2008-2017 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "GearTooth.h"

#include "SmartDashboard/SendableBuilder.h"

using namespace frc;

constexpr double GearTooth::kGearToothThreshold;

/**
 * Common code called by the constructors.
 */
void GearTooth::EnableDirectionSensing(bool directionSensitive) {
  if (directionSensitive) {
    SetPulseLengthMode(kGearToothThreshold);
  }
}

/**
 * Construct a GearTooth sensor given a channel.
 *
 * @param channel            The DIO channel that the sensor is connected to.
 *                           0-9 are on-board, 10-25 are on the MXP.
 * @param directionSensitive True to enable the pulse length decoding in
 *                           hardware to specify count direction.
 */
GearTooth::GearTooth(int channel, bool directionSensitive) : Counter(channel) {
  EnableDirectionSensing(directionSensitive);
  SetName("GearTooth", channel);
}

/**
 * Construct a GearTooth sensor given a digital input.
 *
 * This should be used when sharing digital inputs.
 *
 * @param source             A pointer to the existing DigitalSource object
 *                           (such as a DigitalInput)
 * @param directionSensitive True to enable the pulse length decoding in
 *                           hardware to specify count direction.
 */
GearTooth::GearTooth(DigitalSource* source, bool directionSensitive)
    : Counter(source) {
  EnableDirectionSensing(directionSensitive);
  SetName("GearTooth", source->GetChannel());
}

/**
 * Construct a GearTooth sensor given a digital input.
 *
 * This should be used when sharing digital inputs.
 *
 * @param source             A reference to the existing DigitalSource object
 *                           (such as a DigitalInput)
 * @param directionSensitive True to enable the pulse length decoding in
 *                           hardware to specify count direction.
 */
GearTooth::GearTooth(std::shared_ptr<DigitalSource> source,
                     bool directionSensitive)
    : Counter(source) {
  EnableDirectionSensing(directionSensitive);
  SetName("GearTooth", source->GetChannel());
}

void GearTooth::InitSendable(SendableBuilder& builder) {
  Counter::InitSendable(builder);
  builder.SetSmartDashboardType("Gear Tooth");
}
