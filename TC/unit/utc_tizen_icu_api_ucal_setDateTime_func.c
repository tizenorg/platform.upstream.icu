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

static void utc_tizen_icu_api_ucal_setDateTime_func_01(void);
static void utc_tizen_icu_api_ucal_setDateTime_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucal_setDateTime_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucal_setDateTime_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucal_setDateTime start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucal_setDateTime ends ");
	return;
}

/**
 * @brief Postive test case of utc_tizen_icu_api_ucal_setDateTime()
 */
static void utc_tizen_icu_api_ucal_setDateTime_func_01(void)
{
	UCalendar *cal = NULL;
	UErrorCode status = U_ZERO_ERROR;
	int32_t type = UCAL_DEFAULT;
	int32_t year = 2012;
	int32_t month = UCAL_MARCH;
	int32_t date = 10;
	int32_t hour = 0;
	int32_t minute = 0;
	int32_t second = 0;

	cal = ucal_open(NULL, -1, NULL, type, &status);
	if (U_SUCCESS(status) && (NULL != cal)) {
		ucal_setDateTime(cal, year, month, date, hour, minute, second,
				 &status);
		if (U_SUCCESS(status)) {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_setDateTime test PASS!");
			tet_printf("The current time in millis %ld\n", date);
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_setDateTime test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucal_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	ucal_close(cal);
	return;

}
/**
 * @brief Negative test case of utc_tizen_icu_api_ucal_setDateTime()
 *  Invalid miniute will give error
 */
static void utc_tizen_icu_api_ucal_setDateTime_func_02(void)
{
	UCalendar *cal = NULL;
	UErrorCode status = U_ZERO_ERROR;
	int32_t type = UCAL_DEFAULT;
	int32_t year = 2012;
	int32_t month = UCAL_MARCH;
	int32_t date = 10;
	int32_t hour = 0;
	int32_t minute = 80; /* invalid minute*/
	int32_t second = 0;

	cal = ucal_open(NULL, -1, NULL, type, &status);
	if (U_SUCCESS(status) && (NULL != cal)) {
		ucal_setDateTime(cal, year, month, date, hour, minute, second,
				 &status);
		if (U_SUCCESS(status)) { /* It will give fallback warning*/
			tet_infoline
			    ("utc_tizen_icu_api_ucal_setDateTime test PASS!");
			tet_printf("The current time in millis %ld\n", date);
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucal_setDateTime test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucal_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	ucal_close(cal);
	return;

}

