/*
 * Copyright (c) 1994, 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

/*
 *      Link foreign methods.  This first half of this file contains the
 *      machine independent dynamic linking routines.
 *      See "BUILD_PLATFORM"/java/lang/linker_md.c to see
 *      the implementation of this shared dynamic linking
 *      interface.
 *
 *      NOTE - source in this file is POSIX.1 compliant, host
 *             specific code lives in the platform specific
 *             code tree.
 */

#include "jni.h"
#include "jni_util.h"
#include "jvm.h"

#include "java_lang_Runtime.h"

JNIEXPORT jlong JNICALL
Java_java_lang_Runtime_freeMemory(JNIEnv *env, jobject this)
{
    return JVM_FreeMemory();
}

JNIEXPORT jlong JNICALL
Java_java_lang_Runtime_totalMemory(JNIEnv *env, jobject this)
{
    return JVM_TotalMemory();
}

JNIEXPORT jlong JNICALL
Java_java_lang_Runtime_maxMemory(JNIEnv *env, jobject this)
{
    return JVM_MaxMemory();
}

JNIEXPORT void JNICALL
Java_java_lang_Runtime_gc(JNIEnv *env, jobject this)
{
    JVM_GC();
}

JNIEXPORT jint JNICALL
Java_java_lang_Runtime_availableProcessors(JNIEnv *env, jobject this)
{
    return JVM_ActiveProcessorCount();
}

JNIEXPORT jobject JNICALL
Java_java_lang_Runtime_alloc(JNIEnv *env, jobject this, jclass clazz)
{
    return JVM_Allocate(env, clazz);
}

JNIEXPORT jobjectArray JNICALL
Java_java_lang_Runtime_allocObjArray(JNIEnv *env, jobject this, jclass clazz, jint length)
{
    return JVM_AllocateObjectArray(env, clazz, length);
}

JNIEXPORT jarray JNICALL
Java_java_lang_Runtime_allocIntArray(JNIEnv *env, jobject this, jint length)
{
    return JVM_AllocatePrimitiveArray(env, 10, length);
}

JNIEXPORT jarray JNICALL
Java_java_lang_Runtime_allocDoubleArray(JNIEnv *env, jobject this, jint length)
{
    return JVM_AllocatePrimitiveArray(env, 7, length);
}

JNIEXPORT void JNICALL
Java_java_lang_Runtime_free(JNIEnv *env, jobject this, jobject obj)
{
    JVM_Free(obj);
}

JNIEXPORT void JNICALL
Java_java_lang_Runtime_freeObjArray(JNIEnv *env, jobject this, jobjectArray objArray)
{
    JVM_FreeObjectArray(objArray);
}