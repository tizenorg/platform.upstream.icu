/*
 *  tizen-icu-api
 *
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

static void utc_tizen_icu_api_udat_open_func_01(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_udat_open_func_01, POSITIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_udat_open start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_udat_open ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_udat_open()
 */
static void utc_tizen_icu_api_udat_open_func_01(void)
{
	UDateFormat *date_fmt = NULL;
	const char *locale = uloc_getDefault();
	UErrorCode status = U_ZERO_ERROR;
	int32_t pattern[] = { UDAT_FULL, UDAT_LONG, UDAT_MEDIUM, UDAT_SHORT };
	int32_t i;

	for (i = 0; i < 4; i++) {
		date_fmt =
		    udat_open(UDAT_NONE, pattern[i], locale, NULL, -1, NULL, -1,
			      &status);

		if (U_SUCCESS(status) && (NULL != date_fmt)) {
			tet_infoline("utc_tizen_icu_api_udat_open test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_udat_open test FAIL!");
			tet_printf("Error code %s", u_errorName(status));
			tet_result(TET_FAIL);
		}
		udat_close(date_fmt);
	}

	for (i = 0; i < 4; i++) {
		date_fmt =
		    udat_open(pattern[i], UDAT_NONE, locale, NULL, -1, NULL, -1,
			      &status);

		if (U_SUCCESS(status) && (NULL != date_fmt)) {
			tet_infoline("utc_tizen_icu_api_udat_open test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_udat_open test FAIL!");
			tet_printf("Error code %s", u_errorName(status));
			tet_result(TET_FAIL);
		}
		udat_close(date_fmt);
	}

	for (i = 0; i < 4; i++) {
		date_fmt =
		    udat_open(pattern[i], pattern[i], locale, NULL, -1, NULL,
			      -1, &status);

		if (U_SUCCESS(status) && (NULL != date_fmt)) {
			tet_infoline("utc_tizen_icu_api_udat_open test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline("utc_tizen_icu_api_udat_open test FAIL!");
			tet_printf("Error code %s", u_errorName(status));
			tet_result(TET_FAIL);
		}
		udat_close(date_fmt);
	}

	return;
}
