///
/// Created by ice1000
///

#include "SequenceUtils.h"

using ice1000_sort::insertion_sort;
using ice1000_sort::merge_sort;
using ice1000_sort::bubble_sort;
using ice1000_sort::quick_sort;
using ice1000_sort::comb_sort;
using ice1000_sort::selection_sort;
using ice1000_sort::cocktail_sort;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

/**
 * implemention
 *
 * @param type data type, like Int, Float, Double.
 */
#define __discretization_with(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
auto pair = new ice1000_util::Ice1000Pair<jlong, jint>[len](); \
auto after = ice1000_util::discretization(data, len); \
env->Release ## type ## ArrayElements(_data, data, 0); \
env->Set ## type ## ArrayRegion(_data, 0, len, after); \
__JNI__FUNCTION__CLEAN__ \
delete after; \
delete[] pair;

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_discretization___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__discretization_with(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_discretization___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__discretization_with(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_discretization___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__discretization_with(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_discretization___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__discretization_with(Double);
}

#undef __discretization_with

/**
 * implemention
 *
 * @param type same as __discretization_with
 */
#define __ice_bubble_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
ice1000_sort::bubble_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortBubble___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice_bubble_sort(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortBubble___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice_bubble_sort(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortBubble___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice_bubble_sort(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortBubble___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice_bubble_sort(Double);
}

#undef __ice_bubble_sort

#define __ice1000_quick_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
ice1000_sort::quick_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortQuick___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice1000_quick_sort(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortQuick___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice1000_quick_sort(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortQuick___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice1000_quick_sort(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortQuick___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice1000_quick_sort(Double);
}

#undef __ice1000_quick_sort

#define __ice_insertion_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
ice1000_sort::insertion_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortInsertion___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice_insertion_sort(Int);
}


JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortInsertion___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice_insertion_sort(Long);
}


JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortInsertion___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice_insertion_sort(Float);
}


JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortInsertion___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice_insertion_sort(Double);
}

#undef __ice_insertion_sort

#define __ice_merge_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
ice1000_sort::merge_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortMerge___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice_merge_sort(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortMerge___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice_merge_sort(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortMerge___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice_merge_sort(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortMerge___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice_merge_sort(Double);
}

#undef __ice_merge_sort

#define __ice_comb_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
comb_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortComb___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice_comb_sort(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortComb___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice_comb_sort(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortComb___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice_comb_sort(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortComb___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice_comb_sort(Double);
}

#undef __ice_comb_sort

#define __ice_selection_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
selection_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortSelection___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice_selection_sort(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortSelection___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice_selection_sort(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortSelection___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice_selection_sort(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortSelection___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice_selection_sort(Double);
}

#undef __ice_selection_sort

#define __ice_cocktail_sort(type) \
__JNI__FUNCTION__INIT__ \
auto data = env->Get ## type ## ArrayElements(_data, option); \
cocktail_sort(data, len); \
env->Set ## type ## ArrayRegion(_data, 0, len, data); \
__JNI__FUNCTION__CLEAN__

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortCocktail___3II(
		JNIEnv *env,
		jclass,
		jintArray _data,
		jint len) -> void {
	__ice_cocktail_sort(Int);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortCocktail___3JI(
		JNIEnv *env,
		jclass,
		jlongArray _data,
		jint len) -> void {
	__ice_cocktail_sort(Long);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortCocktail___3FI(
		JNIEnv *env,
		jclass,
		jfloatArray _data,
		jint len) -> void {
	__ice_cocktail_sort(Float);
}

JNIEXPORT auto JNICALL Java_org_ice1000_util_SequenceUtils_sortCocktail___3DI(
		JNIEnv *env,
		jclass,
		jdoubleArray _data,
		jint len) -> void {
	__ice_cocktail_sort(Double);
}

#undef __ice_cocktail_sort

#pragma clang diagnostic pop