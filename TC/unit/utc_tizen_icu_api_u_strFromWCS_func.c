 /*
  * Copyright (c) 2000 - 2012 Samsung Electronics Co., Ltd. All rights reserved.
  *
  * Contact: Jayoun Lee <airjany@samsung.com>
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  * http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  */

#include <tet_api.h>
#include <unicode/utypes.h>
#include <unicode/uloc.h>
#include <unicode/ucal.h>
#include <unicode/udat.h>
#include <unicode/unum.h>
#include <unicode/ucnv.h>
#include <unicode/ustring.h>
#include <unistd.h>
#include<unicode/utmscale.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup) (void) = startup;
void (*tet_cleanup) (void) = cleanup;

static void utc_tizen_icu_api_u_strFromWCS_func_01(void);
static void utc_tizen_icu_api_u_strFromWCS_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_u_strFromWCS_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_u_strFromWCS_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_u_strFromWCS start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_u_strFromWCS ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_u_strFromWCS()
 */
static void utc_tizen_icu_api_u_strFromWCS_func_01(void)
{
	UChar dest[50];
	int32_t dest_capacity = 50;
	int32_t *pdest_len = &dest_capacity;
	const wchar_t *src = L"hello world";
	int32_t src_len = 12;
	UErrorCode status = U_ZERO_ERROR;
	UChar *result = NULL;

	result =
	    u_strFromWCS(dest, dest_capacity, pdest_len, src, src_len, &status);
	if (U_SUCCESS(status)) {
		tet_infoline("utc_tizen_icu_api_u_strFromWCS test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_u_strFromWCS test FAIL!");
		tet_printf("error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	return;

}

/**
 * @brief Negative test case of utc_tizen_icu_api_u_strFromWCS()
 * sending source as null will return error
 */
static void utc_tizen_icu_api_u_strFromWCS_func_02(void)
{
	UChar dest[50];
	int32_t dest_capacity = 50;
	int32_t *pdest_len = &dest_capacity;
	UErrorCode status = U_ZERO_ERROR;
	UChar *result = NULL;

	result =
	    u_strFromWCS(dest, dest_capacity, pdest_len, NULL, -1, &status);
	if (U_FAILURE(status)) {
		tet_infoline("utc_tizen_icu_api_u_strFromWCS test PASS!");
		tet_result(TET_PASS);
	} else {
		tet_infoline("utc_tizen_icu_api_u_strFromWCS test FAIL!");
		tet_printf("error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	return;

}
