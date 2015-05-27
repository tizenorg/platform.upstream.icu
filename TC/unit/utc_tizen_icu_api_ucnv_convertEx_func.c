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

static void utc_tizen_icu_api_ucnv_convertEx_func_01(void);
static void utc_tizen_icu_api_ucnv_convertEx_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucnv_convertEx_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucnv_convertEx_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucnv_convertEx start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucnv_convertEx ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucnv_convertEx()
 */
static void utc_tizen_icu_api_ucnv_convertEx_func_01(void)
{
	const char *cnv_name1 = "UTF-8";
	const char *cnv_name2 = "US-ASCII";
	UErrorCode status = U_ZERO_ERROR;
	UErrorCode err1 = U_ZERO_ERROR;
	UErrorCode err2 = U_ZERO_ERROR;
	UConverter *src_cnv = NULL;
	UConverter *target_cnv = NULL;
	char output[100];
	int32_t capacity = 100;
	const char *input = "Text here";
	int32_t length = strlen(input);
	char *target = output;
	const char *src = input;

	src_cnv = ucnv_open(cnv_name1, &err1);
	target_cnv = ucnv_open(cnv_name2, &err2);
	if (U_SUCCESS(err1) && (U_SUCCESS(err2))) {
		ucnv_convertEx(target_cnv, src_cnv,
			       &target, output + capacity,
			       &src, input + length, NULL, NULL,
			       NULL, NULL, TRUE, TRUE, &status);

		if (U_SUCCESS(status)) {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_convertEx test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_convertEx test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucnv_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}

	ucnv_close(src_cnv);
	ucnv_close(target_cnv);
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucnv_convertEx()
 * sending target as  null will return error
 */
static void utc_tizen_icu_api_ucnv_convertEx_func_02(void)
{
	const char *cnv_name1 = "UTF-8";
	const char *cnv_name2 = "US-ASCII";
	UErrorCode status = U_ZERO_ERROR;
	UErrorCode err1 = U_ZERO_ERROR;
	UErrorCode err2 = U_ZERO_ERROR;
	UConverter *src_cnv = NULL;
	UConverter *target_cnv = NULL;
	char output[100];
	int32_t capacity = 100;
	const char *input = "Text here";
	int32_t length = strlen(input);
	const char *src = input;

	src_cnv = ucnv_open(cnv_name1, &err1);
	target_cnv = ucnv_open(cnv_name2, &err2);
	if (U_SUCCESS(err1) && (U_SUCCESS(err2))) {
		ucnv_convertEx(target_cnv, src_cnv,
			       NULL, output + capacity,
			       &src, input + length, NULL, NULL,
			       NULL, NULL, TRUE, TRUE, &status);

		if (U_FAILURE(status)) {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_convertEx test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_convertEx test FAIL!");
			tet_printf("Error code %s\n", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucnv_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}

	ucnv_close(src_cnv);
	ucnv_close(target_cnv);
	return;

}
