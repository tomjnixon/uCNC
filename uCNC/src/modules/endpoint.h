/*
	Name: endpoint.h
	Description: Webserver endpoints for µCNC.

	Copyright: Copyright (c) João Martins
	Author: João Martins
	Date: 25-10-2023

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#ifndef ENDPOINT_H
#define ENDPOINT_H

#ifdef __cplusplus
#ifdef MCU_HAS_ENDPOINTS

#ifndef FS_URI
#define FS_URI "/fs"
#define FS_URI_LEN 3
#endif

#define FS_WRITE_GZ_SIZE 343
const char fs_write_page[FS_WRITE_GZ_SIZE] PROGMEM = {0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0a, 0x4d, 0x51, 0xc1, 0x4e, 0xc3, 0x30, 0x0c, 0xbd, 0x23, 0xf1, 0x0f, 0x21, 0x97, 0x6d, 0xd2, 0xda, 0x02, 0x27, 0x04, 0x69, 0x24, 0x18, 0x9b, 0xb4, 0x13, 0x1c, 0xb6, 0x03, 0xc7, 0x34, 0xf1, 0xd6, 0x48, 0x69, 0x12, 0xb5, 0xee, 0xa6, 0xfd, 0x3d, 0x4e, 0x33, 0xd0, 0x0e, 0x89, 0xec, 0x67, 0xfb, 0xf9, 0xd9, 0x16, 0x0f, 0x9f, 0x5f, 0xab, 0xdd, 0xcf, 0xf7, 0x9a, 0xb5, 0xd8, 0x39, 0x29, 0xd2, 0xcf, 0x9c, 0xf2, 0xc7, 0x9a, 0x83, 0xe7, 0xe4, 0x83, 0x32, 0x52, 0x74, 0x80, 0x8a, 0xe9, 0x56, 0xf5, 0x03, 0x60, 0xcd, 0xf7, 0xbb, 0x4d, 0xf1, 0xc2, 0xaf, 0xa8, 0x57, 0x1d, 0xd4, 0xfc, 0x64, 0xe1, 0x1c, 0x43, 0x8f, 0x9c, 0xe9, 0xe0, 0x11, 0x3c, 0x65, 0x9d, 0xad, 0xc1, 0xb6, 0x36, 0x70, 0xb2, 0x1a, 0x8a, 0xc9, 0x59, 0x32, 0xeb, 0x2d, 0x5a, 0xe5, 0x8a, 0x41, 0x2b, 0x07, 0xf5, 0x53, 0xf9, 0x48, 0x2c, 0x68, 0xd1, 0x81, 0xdc, 0x47, 0x17, 0x94, 0x61, 0x07, 0xeb, 0x40, 0x54, 0x19, 0x12, 0x55, 0x6e, 0xde, 0x04, 0x73, 0x21, 0x21, 0xcf, 0x72, 0xbc, 0xcd, 0x21, 0x5f, 0x1c, 0x42, 0xdf, 0x31, 0x6b, 0x6a, 0x9e, 0xa0, 0x0d, 0x39, 0x9c, 0x91, 0xa6, 0x36, 0x10, 0x12, 0xc3, 0x40, 0x62, 0x94, 0x46, 0x1b, 0x7c, 0xcd, 0x39, 0x03, 0xaf, 0xf1, 0x12, 0x49, 0x69, 0x37, 0x3a, 0xb4, 0x51, 0xf5, 0x58, 0xa5, 0xea, 0xc2, 0x28, 0x54, 0x24, 0xc2, 0xa9, 0x06, 0x1c, 0x23, 0x24, 0x73, 0x6d, 0x7d, 0x1c, 0x91, 0xcb, 0x55, 0x1b, 0xc2, 0x00, 0x4c, 0x4d, 0x2d, 0x5f, 0x45, 0x35, 0x65, 0x49, 0x61, 0x53, 0x94, 0x65, 0xba, 0x14, 0xe1, 0xff, 0x1a, 0x72, 0xdd, 0x75, 0x27, 0x37, 0x44, 0xa2, 0xe9, 0xe9, 0x8d, 0x88, 0xc1, 0x5f, 0xeb, 0x86, 0xb1, 0xe9, 0x2c, 0x45, 0xf2, 0xdc, 0xa2, 0xca, 0x41, 0x9a, 0x39, 0xa9, 0x92, 0x62, 0xd0, 0xbd, 0x8d, 0x28, 0x4d, 0xd0, 0x63, 0x47, 0xdb, 0x2c, 0x8f, 0x80, 0x6b, 0x07, 0xc9, 0xfc, 0xb8, 0x6c, 0xcd, 0x7c, 0xf6, 0x37, 0xf0, 0x6c, 0x51, 0xd2, 0x49, 0xde, 0x11, 0x7b, 0x4b, 0x0c, 0x30, 0xe7, 0x79, 0x62, 0xbe, 0x64, 0x2e, 0x68, 0x95, 0xcc, 0x32, 0x2a, 0x6c, 0x93, 0xa0, 0xc5, 0x9b, 0xa8, 0xae, 0xb4, 0xd4, 0x6e, 0xda, 0x69, 0x35, 0xdd, 0xfc, 0xfe, 0xee, 0x17, 0x33, 0xfe, 0xa0, 0x20, 0x05, 0x02, 0x00, 0x00};

#include <Uri.h>
// helper class to allow uri handling for a base address
class UriWildcard : public Uri
{
public:
	UriWildcard(const char *uri) : Uri(uri) {}
	UriWildcard(const String &uri) : Uri(uri) {}
	UriWildcard(const __FlashStringHelper *uri) : Uri(uri) {}
	virtual ~UriWildcard() {}

	Uri *clone() const override
	{
		return new UriWildcard(_uri);
	};

	bool canHandle(const String &requestUri, __attribute__((unused)) std::vector<String> &pathArgs) override
	{
		return requestUri.startsWith(_uri);
	}
};
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "../cnc.h"
#include <stddef.h>

	typedef void (*endpoint_delegate)(void);

	void endpoint_add(const char *uri, uint8_t method, endpoint_delegate request_handler, endpoint_delegate file_handler);
	int endpoint_request_hasargs(void);
	void endpoint_request_uri(char *uri, size_t maxlen);
	bool endpoint_request_arg(const char *argname, char *argvalue, size_t maxlen);
	void endpoint_send(int code, const char *content_type, const char *data);
	void endpoint_send_header(const char *name, const char *data, bool first);
	bool endpoint_send_file(const char *file_path, const char *content_type);

#define ENDPOINT_UPLOAD_START 0
#define ENDPOINT_UPLOAD_PART 1
#define ENDPOINT_UPLOAD_END 2
#define ENDPOINT_UPLOAD_ABORT 3
	typedef struct endpoint_upload_
	{
		uint8_t status;
		uint8_t *data;
		size_t datalen;
	} endpoint_upload_t;

	endpoint_upload_t endpoint_file_upload_status(void);

#define ENDPOINT_ANY 0
#define ENDPOINT_GET 1
#define ENDPOINT_POST 2
#define ENDPOINT_PUT 3
#define ENDPOINT_DELETE 4
#define ENDPOINT_OTHER 128

	uint8_t endpoint_request_method(void);
	void endpoint_file_upload_name(char *filename, size_t maxlen);
	char *endpoint_file_upload_buffer(size_t *len);

#ifdef __cplusplus
}
#endif

#endif