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
 * @file ux_device.hpp
 * @date 9/7/20
 * @version 1.0
 * @brief interface for the platform.
 */
#pragma once

namespace uxdevice {

/**
 * @struct link_table_entry_t
 * @brief this is the structure that is used to communicate the guid and
 * function pointer from the library to the client. This is sent as low level
 * information to avoid std cross API. However the error state and error check
 * might be improved if necessary.
 */
struct link_table_entry_t {
  interface_guid_t alias = interface_alias::link_table_entry_t;
  interface_guid_t guid;
  void *ptr;
};

class client_interface_t {
public:
  client_interface_t() {}
  client_interface_t(const std::string &_library_name, double _version);
  ~client_interface_t() {}

  void initialize(const std::string &_library_name, double _version);
  void terminate(void);

  double system_version = {};
  std::string error_message = {};

  std::function<void(const std::string &)> fn_library_open = {};
  std::function<void(void)> fn_library_close = {};

  std::function<void(const std::string &)> fn_library_symbol = {};
  std::function<std::string(void)> fn_library_error = {};

  std::function<double(void)> fn_system_version = {};
  std::function<std::size_t(double)> fn_guid_interface_linkage_size = {};
  std::function<void(double, void *, std::size_t)> fn_guid_interface_linkage =
      {};

  typedef std::unordered_map<uxapi::interface_guid_t, std::function<void()>>
      interface_guid_map_t;

  static const interface_guid_map_t guid_index;
  std::string library_name = {};
  std::string library_filename = {};
};

} // namespace uxdevice
