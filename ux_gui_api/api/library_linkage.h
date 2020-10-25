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
 * @file library_linkage.hpp
 * @date 10/24/20
 * @version 1.0
 * @brief provides the interface to the ux_gui_library. These std::function
 * objects are filled in by loading the dll and performing a interface query.
 */
#pragma once

/**
 * @class library_interface_linkage_t
 * @brief The member variables of this class are used as API as this class is
 * inherited publicly.
 *
 */
class library_interface_linkage_t {
public:
  std::function<void(client_data_interface_base_t *)> fn_input_resource = {};
  std::function<void(std::size_t)> fn_linked_mapped_objects_find_size_t = {};
  std::function<void(char *, std::size_t)>
      fn_linked_mapped_objects_find_string = {};

  std::function<void(void)> fn_save = {};
  std::function<void(void)> fn_restore;
  std::function<void(content_type_t &)> fn_push;
  std::function<void(bool)> fn_pop;

  std::function<void(double, double)> fn_scale;
  std::function<void(matrix_t &)> fn_transform;
  std::function<void(matrix_t &)> fn_matrix;
  std::function<void(void)> fn_identity;
  std::function<void(double, double)> fn_translate;
  std::function<void(double)> fn_rotate;

  std::function<void(double, double)> fn_device;
  std::function<void(double, double)> fn_device_distance;
  std::function<void(double, double)> fn_device_offset;
  std::function<void(double, double)> fn_device_scale;

  std::function<void(double, double)> fn_user;
  std::function<void(double, double)> fn_user_distance;

  std::function<void(void)> fn_notify_complete;
}; // namespace uxdevice
