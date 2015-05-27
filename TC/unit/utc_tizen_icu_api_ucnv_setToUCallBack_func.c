 /*
  * Copyright (c) 2000 - 2012 Samsung Electronics Co., Ltd. All rights reserved.
  *
  * Contact: Hakjoo ko <hakjoo.ko@samsung.com>
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

static void utc_tizen_icu_api_ucnv_setToUCallBack_func_01(void);
static void utc_tizen_icu_api_ucnv_setToUCallBack_func_02(void);

enum {
	POSITIVE_TC_IDX = 0x01,
	NEGATIVE_TC_IDX,
};

struct tet_testlist tet_testlist[] = {
	{utc_tizen_icu_api_ucnv_setToUCallBack_func_01, POSITIVE_TC_IDX},
	{utc_tizen_icu_api_ucnv_setToUCallBack_func_02, NEGATIVE_TC_IDX},
	{NULL, 0}
};

static void startup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucnv_setToUCallBack start");
	return;
}

static void cleanup(void)
{
	tet_infoline("Testing API utc_tizen_icu_api_ucnv_setToUCallBack ends ");
	return;
}

/**
 * @brief Positive test case of utc_tizen_icu_api_ucnv_setToUCallBack()
 */
static void utc_tizen_icu_api_ucnv_setToUCallBack_func_01(void)
{
	const char *converter_name = "UTF-8";
	UErrorCode status = U_ZERO_ERROR;
	UConverter *cnv = NULL;
	UConverterToUCallback oldToUAction = NULL;
	UConverterToUCallback oldToUAction2 = NULL;
	const void* oldToUContext = NULL;
	const void* oldToUContext2 = NULL;
	UChar newToUContext = 0x0000;

	cnv = ucnv_open(converter_name, &status);
	if (U_SUCCESS(status) && (NULL != cnv)) {
		ucnv_getToUCallBack(cnv, &oldToUAction, &oldToUContext);
		ucnv_setToUCallBack(cnv, UCNV_TO_U_CALLBACK_SUBSTITUTE, &newToUContext, &oldToUAction2, &oldToUContext2, &status);
		if (U_FAILURE(status) || oldToUAction != oldToUAction2 || oldToUContext != oldToUContext2) {
			tet_infoline
                            ("utc_tizen_icu_api_ucnv_setToUCallBack test FAIL!");
                        tet_printf("Error code %s\n", u_errorName(status));
                        tet_result(TET_FAIL);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_setToUCallBack test PASS!");
			tet_result(TET_PASS);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucnv_open test FAIL!");
		tet_printf("Error code %s", u_errorName(status));
		tet_result(TET_FAIL);
	}

	ucnv_close(cnv);
	return;
}

/**
 * @brief Negative test case of utc_tizen_icu_api_ucnv_setToUCallBack()
 * sending callback function as null will return error
 */
static void utc_tizen_icu_api_ucnv_setToUCallBack_func_02(void)
{
	const char *converter_name = "UTF-8";
	UErrorCode status = U_ZERO_ERROR;
	UConverter *cnv = NULL;
	UChar newToUContext = 0x0000;
	cnv = ucnv_open(converter_name, &status);

	if (U_SUCCESS(status) && (NULL != cnv)) {
		status = U_ILLEGAL_ARGUMENT_ERROR;
		ucnv_setToUCallBack(cnv, UCNV_TO_U_CALLBACK_STOP, &newToUContext, NULL, NULL, &status);
		if (U_FAILURE(status)) {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_setToUCallBack test PASS!");
			tet_result(TET_PASS);
		} else {
			tet_infoline
			    ("utc_tizen_icu_api_ucnv_setToUCallBack test FAIL!");
			tet_printf("Error code %s", u_errorName(status));
			tet_result(TET_FAIL);
		}
	} else {
		tet_infoline("utc_tizen_icu_api_ucnv_open test FAIL!");
		tet_printf("Error code %s\n", u_errorName(status));
		tet_result(TET_FAIL);
	}

	ucnv_close(cnv);
	return;

}
