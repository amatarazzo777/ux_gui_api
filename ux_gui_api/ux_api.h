#pragma once
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
 * @file ux_gui_stream.hpp
 * @date 10/21/20
 * @version 1.0
 * @brief introduces the interface for the platform by product name using the
 * file. The file should assume a lib_ux_gui.h for introduction to the
 * developer.
 *
 * compile options are in the file <api/options.h>.
 *
 * <base/render_base.h> is where the inclusion of os and cairo headers.
 *
 */

// clang-format off
#include <api/options.h>
#include <api/client_interface.h>
#include <api/enums.h>
#include <api/indirect_index.h>
#include <api/interface_guid.h>
#include <api/key_storage.h>
#include <api/library_linkage.h>
#include <api/listeners.h>
#include <api/matrix.h>
#include <api/typed_index.h>

#include <api_declaration.h>

// clang-format on
