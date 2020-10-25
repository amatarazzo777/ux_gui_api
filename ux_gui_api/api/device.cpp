/*
 * This file is part of the ux_gui_stream distribution
 * (https://github.com/amatarazzo777/ux_gui_stream).
 * Copyright (c) 2020 Anthony Matarazzo.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @author Anthony Matarazzo
 * @file device.cpp
 * @date 9/7/20
 * @version 1.0
 * @brief rendering and platform services.
 * @details The file is the client API interface published the system. The main
 * class implementations are for surface_area_t. The rendering and message loops
 * for the base OS services are within this file. The start_processing function
 * is called by the window initialization constructors to create two threads,
 * one for the message queue and one for the rendering loop.
 */

// clang-format off
#include <api/options.h>
#include <base/platform/object.h>
#include <base/platform/window.h>
#include <base/unit_object.h>

#include <base/render_base.h>
#include <api/units.h>

#include "device.h"
// clang-format on

using namespace std;
using namespace uxdevice;

// copy constructor
uxdevice::surface_area_t::surface_area_t(const surface_area_t &other)
    : system_error_t(other), fnEvents(other.fnEvents) {
  if (other.bProcessing)
    bProcessing = true;
}

// move constructor
uxdevice::surface_area_t::surface_area_t(surface_area_t &&other) noexcept
    : system_error_t(other), fnEvents(other.fnEvents) {
  if (other.bProcessing)
    bProcessing = true;
}

// copy assignment operator
uxdevice::surface_area_t &
uxdevice::surface_area_t::operator=(const surface_area_t &other) {
  system_error_t::operator=(other);

  fnEvents = other.fnEvents;

  if (other.bProcessing)
    bProcessing = true;
  return *this;
}

// move assignment operator
uxdevice::surface_area_t &operator=(surface_area_t &&other) noexcept {
  system_error_t::operator=(other);

  fnEvents = std::move(other.fnEvents);

  if (other.bProcessing)
    bProcessing = true;
  return *this;
}

/**
 * @internal
 * @brief Destructor, closes a window on the target OS
 */
uxdevice::surface_area_t::~surface_area_t(void) {}

/**
 * @internal
 * @brief sets the defaults for the context. font, colors, etc.
 */
void surface_area_t::set_surface_defaults(void){SYSTEM_DEFAULTS}

/**
 * @brief API interface, just data is passed to objects. Objects are dynamically
 * allocated as classes derived from a unit base. Mutex is used one display list
 * to not get in the way of the rendering loop,
 */

/**
 * @internal
 * @overload
 * @fn stream input
 * @param const std::string &s
 * @brief A stream interface routine that is declared using the
 * UX_DECLARE_STREAM_INTERFACE macro within the device published development
 * API. ux_device.hpp is where this is interface is declared.  The routine is
 * specialized because it creates a textual_rendering_t object that accepts the
 * textual data. Textual data is stored in a separate object. The
 * textual_rendering_t object encapsulates the pango cairo API functions which
 * is also added.
 */

surface_area_t &uxdevice::surface_area_t::stream_input(const std::string &s) {

  /** @brief allocate one. this is an internal representation. */
  auto *obj = new raw_std_string_t(data);

  /** @brief if the object was created internally, other aspects abut the
   * object may provide operating characteristics on how the context and
   * render react to data changes. */
  obj->interface(interface_guid_t::created_internally_not_shared_t);

  /** @brief the recipient (ux_gui_library) decodes this as any other interface
   * query. The size is also known about compared to the normal c_str which does
   * improve memory transfer when compiled with optimization. Block moves.
   */
  obj->interface(interface_guid_t::raw_std_string_t);

  /** @brief ship the resource to the library. The system will process this
   * matching the interface guid with logic on how to exactly decode it. This is
   * simply a pointer cast.*/
  fn_input_resource(obj);

  /// @brief free
  delete obj;

  return *this;
}

/**
 * @overload
 * @internal
 * @fn stream input
 * @param const std::shared_ptr<std::string> _val
 * @brief An overloaded stream interface implemetatione that is declared using
 * the UX_DECLARE_STREAM_INTERFACE macro inside the uxdevice::surface_area_t
 * class.
 * @details The routine is specialized because it creates a textual_rendering_t
 * object that accepts the textual data. Textual data is stored in a separate
 * object. The textual_rendering_t object encapsulates the pango cairo API
 * functions.
 */
surface_area_t &uxdevice::surface_area_t::stream_input(
    const std::shared_ptr<std::string> _val) {

  /** @brief allocate one. this is an internal representation. */
  auto *obj = new raw_std_string_t(val.data(), val.size());

  /** @brief The object is a shared_ptr. The interface is applied so that
   * mutex operations may occur. The client within their code must also use
   * the mutex.
   */
  obj->interface(interface_guid_t::shared_resource_t);

  /** @brief the recipient (ux_gui_library) decodes this as any other
   * interface query. The size is also known about compared to the normal
   * c_str which does improve memory transfer when compiled with optimization.
   * Block moves.
   */
  obj->interface(interface_guid_t::raw_std_string_t);

  /** @brief ship the resource to the library. The system applies the
   * shared_resource_t behavior when dealing with this resource. */
  fn_input_resource(obj);

  /// @brief free
  delete obj;

  return *this;
}
