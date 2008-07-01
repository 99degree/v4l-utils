/*
#             (C) 2008 Hans de Goede <j.w.r.degoede@hhs.nl>

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 2.1 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __LIBV4LCONVERT_PRIV_H
#define __LIBV4LCONVERT_PRIV_H

#include <stdio.h>
#include "libv4lconvert.h"
#include "tinyjpeg.h"

#ifndef V4L2_PIX_FMT_SPCA501
#define V4L2_PIX_FMT_SPCA501 v4l2_fourcc('S','5','0','1')
#endif

#ifndef V4L2_PIX_FMT_SPCA561
#define V4L2_PIX_FMT_SPCA561 v4l2_fourcc('S','5','6','1')
#endif

#ifndef V4L2_PIX_FMT_SGBRG8
#define V4L2_PIX_FMT_SGBRG8 v4l2_fourcc('G','B','R','G')
#endif

#ifndef V4L2_PIX_FMT_SGRBG8
#define V4L2_PIX_FMT_SGRBG8 v4l2_fourcc('G','R','B','G')
#endif

#ifndef V4L2_PIX_FMT_SRGGB8
#define V4L2_PIX_FMT_SRGGB8 v4l2_fourcc('R','G','G','B')
#endif

#define V4LCONVERT_ERROR_MSG_SIZE 256

#define V4LCONVERT_ERR(...) \
  snprintf(data->error_msg, V4LCONVERT_ERROR_MSG_SIZE, \
  "v4l-convert: error " __VA_ARGS__)


struct v4lconvert_data {
  int fd;
  int supported_src_formats; /* bitfield */
  int no_formats;
  char error_msg[V4LCONVERT_ERROR_MSG_SIZE];
  struct jdec_private *jdec;
};


void v4lconvert_yuv420_to_bgr24(const unsigned char *src, unsigned char *dst,
  int width, int height);

void v4lconvert_spca501_to_yuv420(const unsigned char *src, unsigned char *dst,
  int width, int height);

void v4lconvert_spca501_to_bgr24(const unsigned char *src, unsigned char *dst,
  int width, int height);

void v4lconvert_decode_spca561(const unsigned char *src, unsigned char *dst,
  int width, int height);

void v4lconvert_bayer_to_bgr24(const unsigned char *bayer,
  unsigned char *rgb, int width, int height, unsigned int pixfmt);

void v4lconvert_bayer_to_yuv420(const unsigned char *bayer,
  unsigned char *yuv, int width, int height, unsigned int pixfmt);

#endif
