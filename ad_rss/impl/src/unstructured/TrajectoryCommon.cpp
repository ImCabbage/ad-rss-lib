
// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020 Intel Corporation
//
// SPDX-License-Identifier: LGPL-2.1-only
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#include "TrajectoryCommon.hpp"
#include <ad/physics/Operation.hpp>

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace rss
 */
namespace rss {
/*!
 * @brief namespace unstructured
 */
namespace unstructured {

Point getVehicleCorner(TrajectoryPoint const &point,
                       ad::physics::Dimension2D const &vehicleDimension,
                       VehicleCorner const corner)
{
  Point resultPoint;
  auto const vehicleAngle = point.angle - ad::physics::cPI_2;
  switch (corner)
  {
    case VehicleCorner::frontLeft:
      resultPoint = rotateAroundPoint(
        point.position, toPoint(-vehicleDimension.width / 2.0, vehicleDimension.length / 2.0), vehicleAngle);
      break;
    case VehicleCorner::frontRight:
      resultPoint = rotateAroundPoint(
        point.position, toPoint(vehicleDimension.width / 2.0, vehicleDimension.length / 2.0), vehicleAngle);
      break;
    case VehicleCorner::backLeft:
      resultPoint = rotateAroundPoint(
        point.position, toPoint(-vehicleDimension.width / 2.0, -vehicleDimension.length / 2.0), vehicleAngle);
      break;
    case VehicleCorner::backRight:
      resultPoint = rotateAroundPoint(
        point.position, toPoint(vehicleDimension.width / 2.0, -vehicleDimension.length / 2.0), vehicleAngle);
      break;
    default:
      throw std::runtime_error("unstructured::getVehicleCorner>> invalid corner requested");
      break;
  }
  return resultPoint;
}

} // namespace unstructured
} // namespace rss
} // namespace ad
