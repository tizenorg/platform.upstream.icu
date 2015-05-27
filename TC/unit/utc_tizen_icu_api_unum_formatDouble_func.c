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

static void utc_tizen_icu_api_unum_formatDouble_func_01(void);
static void utc_tizen_icu_api_unum_formatDouble_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_unum_formatDouble_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_unum_formatDouble_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_unum_formatDouble start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_unum_formatDouble ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_unum_formatDouble()
 */
static void utc_tizen_icu_api_unum_formatDouble_func_01(void)
{
	uint32_t index = 0;
	UErrorCode status = U_ZERO_ERROR;
	double number[] = { 5.0, 6.2, -1.7 };
	UNumberFormat *num_fmt = NULL;
	UChar result[20] = { 0, };
	uint32_t ret;

	num_fmt = unum_open(UNUM_DEFAULT, NULL, -1, NULL, NULL, &status);
	if (U_SUCCESS(status) && (NULL != num_fmt)) {

		for (index = 0; index < 3; index++) {
			ret =
			    unum_formatDouble(num_fmt, number[index], result,
					      20, NULL, &status);
			if (U_SUCCESS(status)) {
				tet_infoline
				    ("utc_tizen_icu_api_unum_formatDouble test PASS!");
				tet_printf
				    ("Input number %f formatted result %s\n",
				     number[index], result);
				memset(result, '\0', 20);
				tet_result(TET_PASS);
			} else {
				tet_infoline
				    ("utc_tizen_icu_api_unum_formatDouble test FAIL!");
				tet_printf("Error code %s\n",
					   u_errorName(status));
				tet_result(TET_FAIL);
			}
		}
	} else {
		tet_infoline("utc_tizen_icu_api_unum_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	unum_close(num_fmt);
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_unum_formatDouble()
 * passing result NULL will give BUFFER_OVERFLOW error
 */
static void utc_tizen_icu_api_unum_formatDouble_func_02(void)
{
	UErrorCode status = U_ZERO_ERROR;
	double number = 9.0;
	UNumberFormat *num_fmt = NULL;
	uint32_t ret;

	num_fmt = unum_open(UNUM_DEFAULT, NULL, -1, NULL, NULL, &status);
	if (U_SUCCESS(status) && (NULL != num_fmt)) {
		ret =
		    unum_formatDouble(num_fmt, number, NULL, 20, NULL, &status);
		if (U_FAILURE(status)) {
			tet_infoline
			    ("utc_tizen_icu_api_unum_formatDouble test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_unum_formatDouble test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_unum_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}
	unum_close(num_fmt);
	return;

}
