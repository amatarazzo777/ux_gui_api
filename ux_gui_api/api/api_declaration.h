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
 * @file api_declaration.h
 * @date 9/7/20
 * @version 1.0
 * @brief The api object hold only the information needed. As the items are
 * accounted for with only an 16byte GUID and their raw information, the
 * ux_gui_library receives this and matches this against an allocator
 * internally. This provides the ability to only have far less exports and have
 * an automatic allocator tied to the input stream on the other side.
 *
 * Shared resources are managed and owned by the client as desired, however a
 * mutex is needed. The system simplifies this by base api which the library
 * uses in partnership.
 *
 * This is one way to provide a base for the client and library .so using
 * templates. The system also integrates object dispatch version and raw data
 * passage. The guids on the system are linked compiled to these structures. So
 * the header file ties a version of the interface. When the library is loaded,
 * this is communicated with the ux_gui_library.
 *
 * So there are two general parts of the system: ux_gui_api and ux_gui_library.
 * The interface.guid file ties the numerical identities of those in a component
 * oriented fashion. While identities such as these (16 bytes) are quite unique
 * this provides a though fashion that provides dynamic runtime loading of
 * other types of components using these are interface signatures.
 *
 * THe ability for example to provide a component interface as a rendering
 * visitor within the graphic pipeline is complimented by this signature design.
 * The component will need the drawing context, and perhaps items in pipeline
 * memory. So being able to tie the signature to an abastract_emit_fn_P1_P2_t
 * gives it its visitation right within the pipeline acquire and pipeline_visit;
 * These are functions and designs not currently implemented. This file merely
 * identifies the objects as being unique within the domain by signature.
 *
 *
 */
#pragma once

namespace uxapi {

class absolute_coordinate_t : public typed_index_t<absolute_coordinate_t> {
public:
  interface_guid_t alias = interface_alias::absolute_coordinate_t;
};

class coordinate_t : public typed_index_t<coordinate_t> {
  coordinate_t(double _x, double _y, double _w, double _h)
      : x(_x), y(_y), w(_w), h(_h) {}
  coordinate_t(double _x, double _y) : x(_x), y(_y) {}
  interface_guid_t alias = interface_alias::coordinate_t;
};

class relative_coordinate_t : public typed_index_t<relative_coordinate_t> {
public:
  interface_guid_t alias = interface_alias::relative_coordinate_t;
};

class image_block_t : public typed_index_t<image_block_t> {
  std::string description = {};
  using image_block_storage_t::image_block_storage_t;
  interface_guid_t alias = interface_alias::image_block_t;
};

class mask_t : public typed_index_t<mask_t>, public painter_brush_t {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::mask_t;
};

class fill_path_t : public typed_index_t<fill_path_t>, public painter_brush_t {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::fill_path_t;
};

class paint_t : public typed_index_t<paint_t> {
public:
  value = {};
  interface_guid_t alias = interface_alias::paint_t;
};

class stroke_fill_path_t : public typed_index_t<stroke_fill_path_t> {
  stroke_fill_path_storage_t(const painter_brush_t &f, const painter_brush_t &s)
      : fill_brush(f), stroke_brush(s) {}

  painter_brush_t fill_brush = {};
  painter_brush_t stroke_brush = {};
  interface_guid_t alias = interface_alias::stroke_fill_path_t;
};

class stroke_path_t : public typed_index_t<stroke_path_t>,
                      public painter_brush_t {
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::stroke_path_t;
};

class antialias_t : public typed_index_t<antialias_t> {
public:
  antialias_options_t value = {};
  interface_guid_t alias = interface_alias::antialias_t;
};

class graphic_operator_t : public typed_index_t<graphic_operator_t> {
  graphic_operator_options_t value = {};
  interface_guid_t alias = interface_alias::graphic_operator_t;
};

class line_cap_t : public typed_index_t<line_cap_t> {
  line_cap_options_t value = {};
  interface_guid_t alias = interface_alias::line_cap_t;
}

class line_dashes_t : public typed_index_t<line_dashes_t> {
public:
  std::vector<double> value = {};
  double offset = {};

  interface_guid_t alias = interface_alias::line_dashes_t;
};

class line_join_t : public typed_index_t<line_join_t> {
public:
  line_join_options_t value = {};
  interface_guid_t alias = interface_alias::line_join_t;
};

class line_width_t : public typed_index_t<line_width_t> {
public:
  double value = {};
  interface_guid_t alias = interface_alias::line_width_t;
};

class miter_limit_t : public typed_index_t<miter_limit_t> {
public:
  double value = {};
  interface_guid_t alias = interface_alias::miter_limit_t;
};

class tollerance_t : public typed_index_t<tollerance_t> {
public
  double value = {};
  interface_guid_t alias = interface_alias::tollerance_t;
};

class arc_t : public typed_index_t<arc_t> {
public:
  double xc = {};
  double yc = {};
  double radius = {};
  double angle1 = {};
  double angle2 = {};
  interface_guid_t alias = interface_alias::arc_t;
};

class close_path_t : public typed_index_t<close_path_t> {
public:
  interface_guid_t alias = interface_alias::close_path_t;
};

class curve_t : public typed_index_t<curve_t>, public interface_alias::curve_t {
public:
  double x1 = {};
  double y1 = {};
  double x2 = {};
  double y2 = {};
  double x3 = {};
  double y3 = {};
  interface_guid_t alias = interface_alias::curve_t;
};

class hline_t : public typed_index_t<hline_t> {
public:
  double value = {};
  interface_guid_t alias = interface_alias::hline_t;
};

class line_t : public typed_index_t<line_t> {
public:
  double x = {};
  double y = {};
  interface_guid_t alias = interface_alias::line_t;
};

class negative_arc_t : public typed_index_t<negative_arc_t> {
public:
  double xc = {};
  double yc = {};
  double radius = {};
  double angle1 = {};
  double angle2 = {};
  interface_guid_t alias = interface_alias::negative_arc_t;
};

class vline_t : public typed_index_t<vline_t> {
public:
  double value = {};
  interface_guid_t alias = interface_alias::vline_t;
};

class rectangle_t : public typed_index_t<rectangle_t> {
public:
  double x = {};
  double y = {};
  double width = {};
  double height = {};
  interface_guid_t alias = interface_alias::rectangle_t;
};

class surface_area_brush_t : public typed_index_t<surface_area_brush_t>,
                             public painter_brush_t {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::surface_area_brush_t;
};

class surface_area_title_t : public typed_index_t<surface_area_title_t> {
public:
  std::string value = {};
  interface_guid_t alias = interface_alias::surface_area_title_t;
};

class text_alignment_t : public typed_index_t<text_alignment_t> {
public:
  text_alignment_options_t value = {};
  interface_guid_t alias = interface_alias::text_alignment_t;
};

class text_color_t : public typed_index_t<text_color_t>, public painter_brush {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::text_color_t;
};

class text_data_t : public typed_index_t<text_data_t>,
                    public text_data_storage_t {
public:
  using text_data_storage_t::text_data_storage_t;
  interface_guid_t alias = interface_alias::text_data_t;
};

class text_ellipsize_t : public typed_index_t<text_ellipsize_t> {
public:
  text_ellipsize_options_t value = {};
  interface_guid_t alias = interface_alias::text_ellipsize_t;
};

class text_fill_t : public typed_index_t<text_fill_t>, public painter_brush_t {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::text_fill_t;
};

class text_font_t : public typed_index_t<text_font_t> {
public:
  std::string description = {};
  interface_guid_t alias = interface_alias::text_font_t;
};

class text_indent_t : public typed_index_t<text_indent_t> {
public:
  double value = {};
  interface_guid_t alias = interface_alias::text_indent_t;
};

class text_line_space_t : public typed_index_t<text_line_space_t> {
public:
  double value = {};
  interface_guid_t alias = interface_alias::text_line_space_t;
};

class text_render_normal_t : public typed_index_t<absolute_coordinate_t> {
public:
  interface_guid_t alias = interface_alias::text_render_normal_t;
};

class text_outline_t : public typed_index_t<text_outline_t>,
                       public painter_brush_t {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::text_outline_t;
};

class text_render_path_t : public typed_index_t<text_render_path_t> {
public:
  interface_guid_t alias = interface_alias::text_render_path_t;
};

class text_shadow_t : public typed_index_t<text_shadow_t>,
                      public painter_brush_t {
public:
  using painter_brush_t::painter_brush_t;
  interface_guid_t alias = interface_alias::text_shadow_t;
};

class text_tab_stops_t : public typed_index_t<text_tab_stops_t> {
public:
  std::vector<double> value = {};
  interface_guid_t alias = interface_alias::text_tab_stops_t;
};

} // namespace uxapi
