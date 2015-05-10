; ModuleID = 'runtime/array_runtime.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.10.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%struct.array_table = type { %struct.array_descriptor* }
%struct.array_descriptor = type { i64, i64, i64, i8*, i64, %struct.array_descriptor* }

@__stderrp = external global %struct.__sFILE*
@.str = private unnamed_addr constant [61 x i8] c"Invalid pointer to the array table in `array_add_reference`\0A\00", align 1
@.str1 = private unnamed_addr constant [60 x i8] c"Invalid pointer to the array table in `array_rm_reference`\0A\00", align 1
@.str2 = private unnamed_addr constant [52 x i8] c"Invalid pointer to the array table in `array_size`\0A\00", align 1
@.str3 = private unnamed_addr constant [57 x i8] c"Invalid pointer to the array table in `array_ref_count`\0A\00", align 1
@.str4 = private unnamed_addr constant [58 x i8] c"Invalid pointer to the array table in `array_insert_int`\0A\00", align 1
@.str5 = private unnamed_addr constant [59 x i8] c"Invalid pointer to the array table in `array_insert_bool`\0A\00", align 1
@.str6 = private unnamed_addr constant [60 x i8] c"Invalid pointer to the array table in `array_insert_float`\0A\00", align 1
@.str7 = private unnamed_addr constant [59 x i8] c"Invalid pointer to the array table in `array_insert_char`\0A\00", align 1
@.str8 = private unnamed_addr constant [61 x i8] c"Invalid pointer to the array table in `array_insert_string`\0A\00", align 1
@.str9 = private unnamed_addr constant [53 x i8] c"Invalid pointer to the array table in `array_clear`\0A\00", align 1
@.str10 = private unnamed_addr constant [54 x i8] c"Invalid pointer to the array table in `array_remove`\0A\00", align 1
@.str11 = private unnamed_addr constant [56 x i8] c"Invalid pointer to the array table in `array_push_int`\0A\00", align 1
@.str12 = private unnamed_addr constant [58 x i8] c"Invalid pointer to the array table in `array_push_float`\0A\00", align 1
@.str13 = private unnamed_addr constant [57 x i8] c"Invalid pointer to the array table in `array_push_bool`\0A\00", align 1
@.str14 = private unnamed_addr constant [57 x i8] c"Invalid pointer to the array table in `array_push_char`\0A\00", align 1
@.str15 = private unnamed_addr constant [59 x i8] c"Invalid pointer to the array table in `array_push_string`\0A\00", align 1
@.str16 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `create_array_table`\0A\00", align 1
@.str17 = private unnamed_addr constant [55 x i8] c"Invalid pointer to the array table in `array_set_int`\0A\00", align 1
@.str18 = private unnamed_addr constant [57 x i8] c"Invalid pointer to the array table in `array_set_float`\0A\00", align 1
@.str19 = private unnamed_addr constant [56 x i8] c"Invalid pointer to the array table in `array_set_bool`\0A\00", align 1
@.str20 = private unnamed_addr constant [56 x i8] c"Invalid pointer to the array table in `array_set_char`\0A\00", align 1
@.str21 = private unnamed_addr constant [58 x i8] c"Invalid pointer to the array table in `array_set_string`\0A\00", align 1
@.str22 = private unnamed_addr constant [55 x i8] c"Invalid pointer to the array table in `string_concat`\0A\00", align 1
@.str23 = private unnamed_addr constant [45 x i8] c"Invalid array id or type in `string_concat`\0A\00", align 1
@.str24 = private unnamed_addr constant [54 x i8] c"Invalid pointer to the array table in `print_string`\0A\00", align 1
@.str25 = private unnamed_addr constant [44 x i8] c"Invalid array id or type in `print_string`\0A\00", align 1
@.str28 = private unnamed_addr constant [65 x i8] c"Array index `%zu` out of bounds (array contains %zu element(s))\0A\00", align 1
@bytes_per_type = internal unnamed_addr constant [5 x i64] [i64 4, i64 4, i64 1, i64 1, i64 8], align 16
@.str29 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `array_remove_value`\0A\00", align 1
@.str30 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `array_insert_value`\0A\00", align 1
@.str31 = private unnamed_addr constant [53 x i8] c"Memory allocation failure in `new_array_descriptor`\0A\00", align 1
@array_counter = internal unnamed_addr global i64 1, align 8

; Function Attrs: nounwind ssp uwtable
define i64 @array_allocate_int(%struct.array_table* %table, i64 %size, i32* %populate) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %15, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @array_counter, align 8, !tbaa !1
  %4 = add i64 %3, 1
  store i64 %4, i64* @array_counter, align 8, !tbaa !1
  %5 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %3, i64 %size, i64 0)
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %7 = load %struct.array_descriptor** %6, align 8, !tbaa !5
  %8 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 5
  store %struct.array_descriptor* %7, %struct.array_descriptor** %8, align 8, !tbaa !8
  store %struct.array_descriptor* %5, %struct.array_descriptor** %6, align 8, !tbaa !5
  %9 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 3
  %10 = load i8** %9, align 8, !tbaa !10
  %11 = bitcast i32* %populate to i8*
  %12 = shl i64 %size, 2
  %13 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %10, i1 false)
  %14 = tail call i8* @__memcpy_chk(i8* %10, i8* %11, i64 %12, i64 %13) #4
  br label %15

; <label>:15                                      ; preds = %0, %2
  %.0 = phi i64 [ %3, %2 ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define internal fastcc noalias %struct.array_descriptor* @new_array_descriptor(i64 %id, i64 %size, i64 %type) #0 {
  %1 = tail call i8* @malloc(i64 48) #4
  %2 = bitcast i8* %1 to %struct.array_descriptor*
  %3 = icmp eq i8* %1, null
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str31, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %5)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:7                                       ; preds = %0
  %8 = bitcast i8* %1 to i64*
  store i64 %id, i64* %8, align 8, !tbaa !12
  %9 = getelementptr inbounds i8* %1, i64 8
  %10 = bitcast i8* %9 to i64*
  store i64 %size, i64* %10, align 8, !tbaa !13
  %11 = getelementptr inbounds i8* %1, i64 32
  %12 = bitcast i8* %11 to i64*
  store i64 0, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %1, i64 16
  %14 = bitcast i8* %13 to i64*
  store i64 %type, i64* %14, align 8, !tbaa !15
  %15 = getelementptr inbounds i8* %1, i64 40
  %16 = bitcast i8* %15 to %struct.array_descriptor**
  store %struct.array_descriptor* null, %struct.array_descriptor** %16, align 8, !tbaa !8
  %17 = icmp eq i64 %size, 0
  br i1 %17, label %.thread, label %20

.thread:                                          ; preds = %7
  %18 = getelementptr inbounds i8* %1, i64 24
  %19 = bitcast i8* %18 to i8**
  store i8* null, i8** %19, align 8, !tbaa !10
  br label %31

; <label>:20                                      ; preds = %7
  %21 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %type
  %22 = load i64* %21, align 8, !tbaa !1
  %23 = mul i64 %22, %size
  %24 = tail call i8* @malloc(i64 %23) #4
  %25 = getelementptr inbounds i8* %1, i64 24
  %26 = bitcast i8* %25 to i8**
  store i8* %24, i8** %26, align 8, !tbaa !10
  %27 = icmp eq i8* %24, null
  br i1 %27, label %28, label %31

; <label>:28                                      ; preds = %20
  %29 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %30 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str31, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %29)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:31                                      ; preds = %.thread, %20
  ret %struct.array_descriptor* %2
}

; Function Attrs: nounwind
declare i8* @__memcpy_chk(i8*, i8*, i64, i64) #1

; Function Attrs: nounwind readnone
declare i64 @llvm.objectsize.i64.p0i8(i8*, i1) #2

; Function Attrs: nounwind ssp uwtable
define i64 @array_allocate_float(%struct.array_table* %table, i64 %size, float* %populate) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %15, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @array_counter, align 8, !tbaa !1
  %4 = add i64 %3, 1
  store i64 %4, i64* @array_counter, align 8, !tbaa !1
  %5 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %3, i64 %size, i64 1)
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %7 = load %struct.array_descriptor** %6, align 8, !tbaa !5
  %8 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 5
  store %struct.array_descriptor* %7, %struct.array_descriptor** %8, align 8, !tbaa !8
  store %struct.array_descriptor* %5, %struct.array_descriptor** %6, align 8, !tbaa !5
  %9 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 3
  %10 = load i8** %9, align 8, !tbaa !10
  %11 = bitcast float* %populate to i8*
  %12 = shl i64 %size, 2
  %13 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %10, i1 false)
  %14 = tail call i8* @__memcpy_chk(i8* %10, i8* %11, i64 %12, i64 %13) #4
  br label %15

; <label>:15                                      ; preds = %0, %2
  %.0 = phi i64 [ %3, %2 ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_allocate_string(%struct.array_table* %table, i64 %size, i64* %populate) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %15, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @array_counter, align 8, !tbaa !1
  %4 = add i64 %3, 1
  store i64 %4, i64* @array_counter, align 8, !tbaa !1
  %5 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %3, i64 %size, i64 4)
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %7 = load %struct.array_descriptor** %6, align 8, !tbaa !5
  %8 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 5
  store %struct.array_descriptor* %7, %struct.array_descriptor** %8, align 8, !tbaa !8
  store %struct.array_descriptor* %5, %struct.array_descriptor** %6, align 8, !tbaa !5
  %9 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 3
  %10 = load i8** %9, align 8, !tbaa !10
  %11 = bitcast i64* %populate to i8*
  %12 = shl i64 %size, 3
  %13 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %10, i1 false)
  %14 = tail call i8* @__memcpy_chk(i8* %10, i8* %11, i64 %12, i64 %13) #4
  br label %15

; <label>:15                                      ; preds = %0, %2
  %.0 = phi i64 [ %3, %2 ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_allocate_char(%struct.array_table* %table, i64 %size, i8* %populate) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %13, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @array_counter, align 8, !tbaa !1
  %4 = add i64 %3, 1
  store i64 %4, i64* @array_counter, align 8, !tbaa !1
  %5 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %3, i64 %size, i64 3)
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %7 = load %struct.array_descriptor** %6, align 8, !tbaa !5
  %8 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 5
  store %struct.array_descriptor* %7, %struct.array_descriptor** %8, align 8, !tbaa !8
  store %struct.array_descriptor* %5, %struct.array_descriptor** %6, align 8, !tbaa !5
  %9 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 3
  %10 = load i8** %9, align 8, !tbaa !10
  %11 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %10, i1 false)
  %12 = tail call i8* @__memcpy_chk(i8* %10, i8* %populate, i64 %size, i64 %11) #4
  br label %13

; <label>:13                                      ; preds = %0, %2
  %.0 = phi i64 [ %3, %2 ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_allocate_bool(%struct.array_table* %table, i64 %size, i8* %populate) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %13, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @array_counter, align 8, !tbaa !1
  %4 = add i64 %3, 1
  store i64 %4, i64* @array_counter, align 8, !tbaa !1
  %5 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %3, i64 %size, i64 2)
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %7 = load %struct.array_descriptor** %6, align 8, !tbaa !5
  %8 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 5
  store %struct.array_descriptor* %7, %struct.array_descriptor** %8, align 8, !tbaa !8
  store %struct.array_descriptor* %5, %struct.array_descriptor** %6, align 8, !tbaa !5
  %9 = getelementptr inbounds %struct.array_descriptor* %5, i64 0, i32 3
  %10 = load i8** %9, align 8, !tbaa !10
  %11 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %10, i1 false)
  %12 = tail call i8* @__memcpy_chk(i8* %10, i8* %populate, i64 %size, i64 %11) #4
  br label %13

; <label>:13                                      ; preds = %0, %2
  %.0 = phi i64 [ %3, %2 ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define void @array_add_reference(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([61 x i8]* @.str, i64 0, i64 0), i64 60, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 4
  %16 = load i64* %15, align 8, !tbaa !14
  %17 = add i64 %16, 1
  store i64 %17, i64* %15, align 8, !tbaa !14
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %8
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind
declare i32 @fprintf(%struct.__sFILE* nocapture, i8* nocapture readonly, ...) #1

; Function Attrs: noreturn
declare void @exit(i32) #3

; Function Attrs: nounwind ssp uwtable
define void @array_rm_reference(%struct.array_table* %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([60 x i8]* @.str1, i64 0, i64 0), i64 59, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %array_deallocate.exit, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %array_deallocate.exit.loopexit16, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 4
  %16 = load i64* %15, align 8, !tbaa !14
  %17 = add i64 %16, -1
  store i64 %17, i64* %15, align 8, !tbaa !14
  %.not = icmp eq i64 %17, 0
  br i1 %.not, label %18, label %array_deallocate.exit

; <label>:18                                      ; preds = %14
  %current.04.i = load %struct.array_descriptor** %6, align 8
  %19 = icmp eq %struct.array_descriptor* %current.04.i, null
  br i1 %19, label %array_deallocate.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %18
  br label %.lr.ph.i2

; <label>:20                                      ; preds = %.lr.ph.i2
  %21 = getelementptr inbounds %struct.array_descriptor* %current.06.i, i64 0, i32 5
  %current.0.i1 = load %struct.array_descriptor** %21, align 8
  %22 = icmp eq %struct.array_descriptor* %current.0.i1, null
  br i1 %22, label %array_deallocate.exit.loopexit, label %.lr.ph.i2

.lr.ph.i2:                                        ; preds = %.lr.ph.i2.preheader, %20
  %current.06.i = phi %struct.array_descriptor* [ %current.0.i1, %20 ], [ %current.04.i, %.lr.ph.i2.preheader ]
  %previous.05.i = phi %struct.array_descriptor* [ %current.06.i, %20 ], [ null, %.lr.ph.i2.preheader ]
  %23 = getelementptr inbounds %struct.array_descriptor* %current.06.i, i64 0, i32 0
  %24 = load i64* %23, align 8, !tbaa !12
  %25 = icmp eq i64 %24, %arrid
  br i1 %25, label %26, label %20

; <label>:26                                      ; preds = %.lr.ph.i2
  %previous.05.i.lcssa = phi %struct.array_descriptor* [ %previous.05.i, %.lr.ph.i2 ]
  %current.06.i.lcssa = phi %struct.array_descriptor* [ %current.06.i, %.lr.ph.i2 ]
  %27 = icmp eq %struct.array_descriptor* %previous.05.i.lcssa, null
  %28 = getelementptr inbounds %struct.array_descriptor* %current.06.i.lcssa, i64 0, i32 5
  %29 = load %struct.array_descriptor** %28, align 8, !tbaa !8
  br i1 %27, label %32, label %30

; <label>:30                                      ; preds = %26
  %31 = getelementptr inbounds %struct.array_descriptor* %previous.05.i.lcssa, i64 0, i32 5
  store %struct.array_descriptor* %29, %struct.array_descriptor** %31, align 8, !tbaa !8
  br label %array_descriptor_deallocate.exit.i

; <label>:32                                      ; preds = %26
  store %struct.array_descriptor* %29, %struct.array_descriptor** %6, align 8, !tbaa !5
  br label %array_descriptor_deallocate.exit.i

array_descriptor_deallocate.exit.i:               ; preds = %32, %30
  %33 = getelementptr inbounds %struct.array_descriptor* %current.06.i.lcssa, i64 0, i32 3
  %34 = load i8** %33, align 8, !tbaa !10
  tail call void @free(i8* %34) #4
  %35 = bitcast %struct.array_descriptor* %current.06.i.lcssa to i8*
  tail call void @free(i8* %35) #4
  br label %array_deallocate.exit

array_deallocate.exit.loopexit:                   ; preds = %20
  br label %array_deallocate.exit

array_deallocate.exit.loopexit16:                 ; preds = %8
  br label %array_deallocate.exit

array_deallocate.exit:                            ; preds = %array_deallocate.exit.loopexit16, %array_deallocate.exit.loopexit, %14, %5, %array_descriptor_deallocate.exit.i, %18
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_deallocate(%struct.array_table* %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %.loopexit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.04 = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.04, null
  br i1 %4, label %.loopexit, label %.lr.ph.preheader

.lr.ph.preheader:                                 ; preds = %2
  br label %.lr.ph

; <label>:5                                       ; preds = %.lr.ph
  %6 = getelementptr inbounds %struct.array_descriptor* %current.06, i64 0, i32 5
  %current.0 = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0, null
  br i1 %7, label %.loopexit.loopexit, label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph.preheader, %5
  %current.06 = phi %struct.array_descriptor* [ %current.0, %5 ], [ %current.04, %.lr.ph.preheader ]
  %previous.05 = phi %struct.array_descriptor* [ %current.06, %5 ], [ null, %.lr.ph.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.06, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph
  %previous.05.lcssa = phi %struct.array_descriptor* [ %previous.05, %.lr.ph ]
  %current.06.lcssa = phi %struct.array_descriptor* [ %current.06, %.lr.ph ]
  %12 = icmp eq %struct.array_descriptor* %previous.05.lcssa, null
  %13 = getelementptr inbounds %struct.array_descriptor* %current.06.lcssa, i64 0, i32 5
  %14 = load %struct.array_descriptor** %13, align 8, !tbaa !8
  br i1 %12, label %17, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %previous.05.lcssa, i64 0, i32 5
  store %struct.array_descriptor* %14, %struct.array_descriptor** %16, align 8, !tbaa !8
  br label %array_descriptor_deallocate.exit

; <label>:17                                      ; preds = %11
  store %struct.array_descriptor* %14, %struct.array_descriptor** %3, align 8, !tbaa !5
  br label %array_descriptor_deallocate.exit

array_descriptor_deallocate.exit:                 ; preds = %17, %15
  %18 = getelementptr inbounds %struct.array_descriptor* %current.06.lcssa, i64 0, i32 3
  %19 = load i8** %18, align 8, !tbaa !10
  tail call void @free(i8* %19) #4
  %20 = bitcast %struct.array_descriptor* %current.06.lcssa to i8*
  tail call void @free(i8* %20) #4
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %5
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %2, %0, %array_descriptor_deallocate.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_size(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %8
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %5, %14
  %.0 = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_ref_count(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([57 x i8]* @.str3, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 4
  %16 = load i64* %15, align 8, !tbaa !14
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %8
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %5, %14
  %.0 = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define void @array_insert_int(%struct.array_table* readonly %table, i64 %arrid, i32 %value, i64 %pos) #0 {
  %1 = alloca i32, align 4
  store i32 %value, i32* %1, align 4, !tbaa !16
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([58 x i8]* @.str4, i64 0, i64 0), i64 57, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 0
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = bitcast i32* %1 to i8*
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos, i8* %20)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define internal fastcc void @array_insert_value(%struct.array_descriptor* nocapture %desc, i64 %pos, i8* %val) #0 {
  %1 = getelementptr inbounds %struct.array_descriptor* %desc, i64 0, i32 1
  %2 = load i64* %1, align 8, !tbaa !13
  %3 = icmp ult i64 %2, %pos
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %2) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.array_descriptor* %desc, i64 0, i32 3
  %9 = load i8** %8, align 8, !tbaa !10
  %10 = add i64 %2, 1
  %11 = getelementptr inbounds %struct.array_descriptor* %desc, i64 0, i32 2
  %12 = load i64* %11, align 8, !tbaa !15
  %13 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %12
  %14 = load i64* %13, align 8, !tbaa !1
  %15 = mul i64 %14, %10
  %16 = tail call i8* @realloc(i8* %9, i64 %15) #4
  store i8* %16, i8** %8, align 8, !tbaa !10
  %17 = icmp eq i8* %16, null
  br i1 %17, label %18, label %21

; <label>:18                                      ; preds = %7
  %19 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %20 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str30, i64 0, i64 0), i64 50, i64 1, %struct.__sFILE* %19)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:21                                      ; preds = %7
  %22 = load i64* %11, align 8, !tbaa !15
  %23 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %22
  %24 = load i64* %23, align 8, !tbaa !1
  %25 = mul i64 %24, %pos
  %26 = getelementptr i8* %16, i64 %25
  %.sum = add i64 %25, %24
  %27 = getelementptr i8* %16, i64 %.sum
  %28 = load i64* %1, align 8, !tbaa !13
  %29 = sub i64 %28, %pos
  %30 = mul i64 %29, %24
  %31 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %27, i1 false)
  %32 = tail call i8* @__memmove_chk(i8* %27, i8* %26, i64 %30, i64 %31) #4
  %33 = load i64* %11, align 8, !tbaa !15
  %34 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %33
  %35 = load i64* %34, align 8, !tbaa !1
  %36 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %26, i1 false)
  %37 = tail call i8* @__memcpy_chk(i8* %26, i8* %val, i64 %35, i64 %36) #4
  %38 = load i64* %1, align 8, !tbaa !13
  %39 = add i64 %38, 1
  store i64 %39, i64* %1, align 8, !tbaa !13
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_insert_bool(%struct.array_table* readonly %table, i64 %arrid, i1 zeroext %value, i64 %pos) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %value to i8
  store i8 %2, i8* %1, align 1, !tbaa !18
  %3 = icmp eq %struct.array_table* %table, null
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([59 x i8]* @.str5, i64 0, i64 0), i64 58, i64 1, %struct.__sFILE* %5)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %8, align 8
  %9 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %9, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %7
  br label %.lr.ph.i

; <label>:10                                      ; preds = %.lr.ph.i
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %11, align 8
  %12 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %12, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %10
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %10 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %13 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %14 = load i64* %13, align 8, !tbaa !12
  %15 = icmp eq i64 %14, %arrid
  br i1 %15, label %16, label %10

; <label>:16                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %18 = load i64* %17, align 8, !tbaa !15
  %19 = icmp eq i64 %18, 2
  br i1 %19, label %20, label %find_array_descriptor.exit.thread

; <label>:20                                      ; preds = %16
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos, i8* %1)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %10
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %7, %16, %20
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_insert_float(%struct.array_table* readonly %table, i64 %arrid, float %value, i64 %pos) #0 {
  %1 = alloca float, align 4
  store float %value, float* %1, align 4, !tbaa !20
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([60 x i8]* @.str6, i64 0, i64 0), i64 59, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 1
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = bitcast float* %1 to i8*
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos, i8* %20)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_insert_char(%struct.array_table* readonly %table, i64 %arrid, i8 signext %value, i64 %pos) #0 {
  %1 = alloca i8, align 1
  store i8 %value, i8* %1, align 1, !tbaa !22
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([59 x i8]* @.str7, i64 0, i64 0), i64 58, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 3
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos, i8* %1)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_insert_string(%struct.array_table* readonly %table, i64 %arrid, i64 %value, i64 %pos) #0 {
  %1 = alloca i64, align 8
  store i64 %value, i64* %1, align 8, !tbaa !1
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([61 x i8]* @.str8, i64 0, i64 0), i64 60, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 4
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = bitcast i64* %1 to i8*
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos, i8* %20)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i32 @array_get_int(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = shl i64 %pos, 2
  %25 = getelementptr i8* %23, i64 %24
  %26 = bitcast i8* %25 to i32*
  %27 = load i32* %26, align 4, !tbaa !16
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i32 [ %27, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @array_get_float(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 1
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = shl i64 %pos, 2
  %25 = getelementptr i8* %23, i64 %24
  %26 = bitcast i8* %25 to float*
  %27 = load float* %26, align 4, !tbaa !20
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi float [ %27, %array_get_value.exit ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %11 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_array_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_get_bool(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 2
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = getelementptr i8* %23, i64 %pos
  %25 = load i8* %24, align 1, !tbaa !18, !range !23
  %26 = icmp ne i8 %25, 0
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i1 [ %26, %array_get_value.exit ], [ false, %0 ], [ false, %11 ], [ false, %2 ], [ false, %find_array_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @array_get_char(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 3
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = getelementptr i8* %23, i64 %pos
  %25 = load i8* %24, align 1, !tbaa !22
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i8 [ %25, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_get_string(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 4
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = shl i64 %pos, 3
  %25 = getelementptr i8* %23, i64 %24
  %26 = bitcast i8* %25 to i64*
  %27 = load i64* %26, align 8, !tbaa !1
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i64 [ %27, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define void @array_clear(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str9, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %16 = load i8** %15, align 8, !tbaa !10
  tail call void @free(i8* %16)
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  store i64 0, i64* %17, align 8, !tbaa !13
  store i8* null, i8** %15, align 8, !tbaa !10
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %8
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #1

; Function Attrs: nounwind ssp uwtable
define void @array_remove(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([54 x i8]* @.str10, i64 0, i64 0), i64 53, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %8
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind ssp uwtable
define internal fastcc void @array_remove_value(%struct.array_descriptor* nocapture %desc, i64 %pos) #0 {
  %1 = getelementptr inbounds %struct.array_descriptor* %desc, i64 0, i32 1
  %2 = load i64* %1, align 8, !tbaa !13
  %3 = icmp ugt i64 %2, %pos
  br i1 %3, label %7, label %4

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %2) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.array_descriptor* %desc, i64 0, i32 3
  %9 = load i8** %8, align 8, !tbaa !10
  %10 = getelementptr inbounds %struct.array_descriptor* %desc, i64 0, i32 2
  %11 = load i64* %10, align 8, !tbaa !15
  %12 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %11
  %13 = load i64* %12, align 8, !tbaa !1
  %14 = mul i64 %13, %pos
  %15 = getelementptr i8* %9, i64 %14
  %.sum = add i64 %14, %13
  %16 = getelementptr i8* %9, i64 %.sum
  %17 = xor i64 %pos, -1
  %18 = add i64 %2, %17
  %19 = mul i64 %13, %18
  %20 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %15, i1 false)
  %21 = tail call i8* @__memmove_chk(i8* %15, i8* %16, i64 %19, i64 %20) #4
  %22 = load i8** %8, align 8, !tbaa !10
  %23 = load i64* %10, align 8, !tbaa !15
  %24 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %23
  %25 = load i64* %24, align 8, !tbaa !1
  %26 = load i64* %1, align 8, !tbaa !13
  %27 = add i64 %26, -1
  %28 = mul i64 %27, %25
  %29 = tail call i8* @realloc(i8* %22, i64 %28) #4
  store i8* %29, i8** %8, align 8, !tbaa !10
  %30 = icmp eq i8* %29, null
  br i1 %30, label %31, label %34

; <label>:31                                      ; preds = %7
  %32 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %33 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str29, i64 0, i64 0), i64 50, i64 1, %struct.__sFILE* %32)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:34                                      ; preds = %7
  %35 = load i64* %1, align 8, !tbaa !13
  %36 = add i64 %35, -1
  store i64 %36, i64* %1, align 8, !tbaa !13
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i32 @array_remove_int(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = shl i64 %pos, 2
  %25 = getelementptr i8* %23, i64 %24
  %26 = bitcast i8* %25 to i32*
  %27 = load i32* %26, align 4, !tbaa !16
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i32 [ %27, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @array_remove_float(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 1
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = shl i64 %pos, 2
  %25 = getelementptr i8* %23, i64 %24
  %26 = bitcast i8* %25 to float*
  %27 = load float* %26, align 4, !tbaa !20
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi float [ %27, %array_get_value.exit ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %11 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_array_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_remove_bool(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 2
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = getelementptr i8* %23, i64 %pos
  %25 = load i8* %24, align 1, !tbaa !18, !range !23
  %26 = icmp ne i8 %25, 0
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i1 [ %26, %array_get_value.exit ], [ false, %0 ], [ false, %11 ], [ false, %2 ], [ false, %find_array_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @array_remove_char(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 3
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = getelementptr i8* %23, i64 %pos
  %25 = load i8* %24, align 1, !tbaa !22
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i8 [ %25, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_remove_string(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 4
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = shl i64 %pos, 3
  %25 = getelementptr i8* %23, i64 %24
  %26 = bitcast i8* %25 to i64*
  %27 = load i64* %26, align 8, !tbaa !1
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %pos)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i64 [ %27, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i32 @array_pop_int(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %17, i64 -1)
  %18 = extractvalue { i64, i1 } %uadd, 0
  %19 = extractvalue { i64, i1 } %uadd, 1
  br i1 %19, label %array_get_value.exit, label %20

; <label>:20                                      ; preds = %15
  %21 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %22 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %21, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %18, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %23 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %24 = load i8** %23, align 8, !tbaa !10
  %25 = shl i64 %18, 2
  %26 = getelementptr i8* %24, i64 %25
  %27 = bitcast i8* %26 to i32*
  %28 = load i32* %27, align 4, !tbaa !16
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %18)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i32 [ %28, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @array_pop_float(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 1
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %17, i64 -1)
  %18 = extractvalue { i64, i1 } %uadd, 0
  %19 = extractvalue { i64, i1 } %uadd, 1
  br i1 %19, label %array_get_value.exit, label %20

; <label>:20                                      ; preds = %15
  %21 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %22 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %21, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %18, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %23 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %24 = load i8** %23, align 8, !tbaa !10
  %25 = shl i64 %18, 2
  %26 = getelementptr i8* %24, i64 %25
  %27 = bitcast i8* %26 to float*
  %28 = load float* %27, align 4, !tbaa !20
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %18)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi float [ %28, %array_get_value.exit ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %11 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_array_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_pop_bool(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 2
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %17, i64 -1)
  %18 = extractvalue { i64, i1 } %uadd, 0
  %19 = extractvalue { i64, i1 } %uadd, 1
  br i1 %19, label %array_get_value.exit, label %20

; <label>:20                                      ; preds = %15
  %21 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %22 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %21, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %18, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %23 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %24 = load i8** %23, align 8, !tbaa !10
  %25 = getelementptr i8* %24, i64 %18
  %26 = load i8* %25, align 1, !tbaa !18, !range !23
  %27 = icmp ne i8 %26, 0
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %18)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i1 [ %27, %array_get_value.exit ], [ false, %0 ], [ false, %11 ], [ false, %2 ], [ false, %find_array_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @array_pop_char(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 3
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %17, i64 -1)
  %18 = extractvalue { i64, i1 } %uadd, 0
  %19 = extractvalue { i64, i1 } %uadd, 1
  br i1 %19, label %array_get_value.exit, label %20

; <label>:20                                      ; preds = %15
  %21 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %22 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %21, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %18, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %23 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %24 = load i8** %23, align 8, !tbaa !10
  %25 = getelementptr i8* %24, i64 %18
  %26 = load i8* %25, align 1, !tbaa !22
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %18)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i8 [ %26, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_pop_string(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %find_array_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %4, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %7, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 4
  br i1 %14, label %15, label %find_array_descriptor.exit.thread

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %17, i64 -1)
  %18 = extractvalue { i64, i1 } %uadd, 0
  %19 = extractvalue { i64, i1 } %uadd, 1
  br i1 %19, label %array_get_value.exit, label %20

; <label>:20                                      ; preds = %15
  %21 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %22 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %21, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %18, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit:                             ; preds = %15
  %23 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %24 = load i8** %23, align 8, !tbaa !10
  %25 = shl i64 %18, 3
  %26 = getelementptr i8* %24, i64 %25
  %27 = bitcast i8* %26 to i64*
  %28 = load i64* %27, align 8, !tbaa !1
  tail call fastcc void @array_remove_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %18)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %5
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %2, %11, %0, %array_get_value.exit
  %.0 = phi i64 [ %28, %array_get_value.exit ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %find_array_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define void @array_push_int(%struct.array_table* readonly %table, i64 %arrid, i32 %value) #0 {
  %1 = alloca i32, align 4
  store i32 %value, i32* %1, align 4, !tbaa !16
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([56 x i8]* @.str11, i64 0, i64 0), i64 55, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 0
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = bitcast i32* %1 to i8*
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %21, i8* %22)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_push_float(%struct.array_table* readonly %table, i64 %arrid, float %value) #0 {
  %1 = alloca float, align 4
  store float %value, float* %1, align 4, !tbaa !20
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([58 x i8]* @.str12, i64 0, i64 0), i64 57, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 1
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = bitcast float* %1 to i8*
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %21, i8* %22)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_push_bool(%struct.array_table* readonly %table, i64 %arrid, i1 zeroext %value) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %value to i8
  store i8 %2, i8* %1, align 1, !tbaa !18
  %3 = icmp eq %struct.array_table* %table, null
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([57 x i8]* @.str13, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %5)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %8, align 8
  %9 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %9, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %7
  br label %.lr.ph.i

; <label>:10                                      ; preds = %.lr.ph.i
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %11, align 8
  %12 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %12, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %10
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %10 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %13 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %14 = load i64* %13, align 8, !tbaa !12
  %15 = icmp eq i64 %14, %arrid
  br i1 %15, label %16, label %10

; <label>:16                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %18 = load i64* %17, align 8, !tbaa !15
  %19 = icmp eq i64 %18, 2
  br i1 %19, label %20, label %find_array_descriptor.exit.thread

; <label>:20                                      ; preds = %16
  %21 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %22 = load i64* %21, align 8, !tbaa !13
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %22, i8* %1)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %10
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %7, %16, %20
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_push_char(%struct.array_table* readonly %table, i64 %arrid, i8 signext %value) #0 {
  %1 = alloca i8, align 1
  store i8 %value, i8* %1, align 1, !tbaa !22
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([57 x i8]* @.str14, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 3
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %21, i8* %1)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_push_string(%struct.array_table* readonly %table, i64 %arrid, i64 %value) #0 {
  %1 = alloca i64, align 8
  store i64 %value, i64* %1, align 8, !tbaa !1
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([59 x i8]* @.str15, i64 0, i64 0), i64 58, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 4
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = bitcast i64* %1 to i8*
  call fastcc void @array_insert_value(%struct.array_descriptor* %current.02.i.lcssa, i64 %21, i8* %22)
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %19
  ret void
}

; Function Attrs: nounwind ssp uwtable
define noalias %struct.array_table* @create_array_table() #0 {
  %1 = tail call i8* @malloc(i64 8) #4
  %2 = icmp eq i8* %1, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str16, i64 0, i64 0), i64 50, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = bitcast i8* %1 to %struct.array_table*
  %8 = bitcast i8* %1 to %struct.array_descriptor**
  store %struct.array_descriptor* null, %struct.array_descriptor** %8, align 8, !tbaa !5
  ret %struct.array_table* %7
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind ssp uwtable
define void @delete_array_table(%struct.array_table* nocapture %table) #0 {
  %1 = bitcast %struct.array_table* %table to i8*
  tail call void @free(i8* %1)
  ret void
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_empty(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  %phitmp = icmp eq i64 %16, 0
  br label %array_size.exit

array_size.exit.loopexit:                         ; preds = %8
  br label %array_size.exit

array_size.exit:                                  ; preds = %array_size.exit.loopexit, %5, %14
  %.0.i = phi i1 [ %phitmp, %14 ], [ true, %5 ], [ true, %array_size.exit.loopexit ]
  ret i1 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_make_sequence(%struct.array_table* %table, i64 %a, i64 %b) #0 {
  %i = alloca i64, align 8
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %.array_allocate_int.exit_crit_edge, label %2

.array_allocate_int.exit_crit_edge:               ; preds = %0
  %.pre = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  br label %array_allocate_int.exit

; <label>:2                                       ; preds = %0
  %3 = load i64* @array_counter, align 8, !tbaa !1
  %4 = add i64 %3, 1
  store i64 %4, i64* @array_counter, align 8, !tbaa !1
  %5 = tail call i8* @malloc(i64 48) #4
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %new_array_descriptor.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str31, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %8) #4
  tail call void @exit(i32 1) #5
  unreachable

new_array_descriptor.exit:                        ; preds = %2
  %10 = bitcast i8* %5 to %struct.array_descriptor*
  %11 = bitcast i8* %5 to i64*
  store i64 %3, i64* %11, align 8, !tbaa !12
  %12 = getelementptr inbounds i8* %5, i64 8
  %13 = getelementptr inbounds i8* %5, i64 40
  %14 = bitcast i8* %13 to %struct.array_descriptor**
  %15 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  call void @llvm.memset.p0i8.i64(i8* %12, i8 0, i64 32, i32 8, i1 false)
  %16 = load %struct.array_descriptor** %15, align 8, !tbaa !5
  store %struct.array_descriptor* %16, %struct.array_descriptor** %14, align 8, !tbaa !8
  store %struct.array_descriptor* %10, %struct.array_descriptor** %15, align 8, !tbaa !5
  br label %array_allocate_int.exit

array_allocate_int.exit:                          ; preds = %.array_allocate_int.exit_crit_edge, %new_array_descriptor.exit
  %.pre-phi = phi %struct.array_descriptor** [ %.pre, %.array_allocate_int.exit_crit_edge ], [ %15, %new_array_descriptor.exit ]
  %.0.i = phi i64 [ 0, %.array_allocate_int.exit_crit_edge ], [ %3, %new_array_descriptor.exit ]
  %current.01.i = load %struct.array_descriptor** %.pre-phi, align 8
  %17 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %17, label %find_array_descriptor.exit, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %array_allocate_int.exit
  br label %.lr.ph.i

; <label>:18                                      ; preds = %.lr.ph.i
  %19 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %19, align 8
  %20 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %20, label %find_array_descriptor.exit.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %18
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %18 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %21 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %22 = load i64* %21, align 8, !tbaa !12
  %23 = icmp eq i64 %22, %.0.i
  br i1 %23, label %find_array_descriptor.exit.loopexit, label %18

find_array_descriptor.exit.loopexit:              ; preds = %.lr.ph.i, %18
  %.0.i1.ph = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ], [ null, %18 ]
  br label %find_array_descriptor.exit

find_array_descriptor.exit:                       ; preds = %find_array_descriptor.exit.loopexit, %array_allocate_int.exit
  %.0.i1 = phi %struct.array_descriptor* [ null, %array_allocate_int.exit ], [ %.0.i1.ph, %find_array_descriptor.exit.loopexit ]
  store i64 %a, i64* %i, align 8, !tbaa !1
  %24 = icmp ugt i64 %a, %b
  br i1 %24, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %find_array_descriptor.exit
  %25 = getelementptr inbounds %struct.array_descriptor* %.0.i1, i64 0, i32 1
  %26 = bitcast i64* %i to i8*
  br label %27

; <label>:27                                      ; preds = %.lr.ph, %27
  %28 = load i64* %25, align 8, !tbaa !13
  call fastcc void @array_insert_value(%struct.array_descriptor* %.0.i1, i64 %28, i8* %26)
  %29 = load i64* %i, align 8, !tbaa !1
  %30 = add i64 %29, 1
  store i64 %30, i64* %i, align 8, !tbaa !1
  %31 = icmp ugt i64 %30, %b
  br i1 %31, label %._crit_edge.loopexit, label %27

._crit_edge.loopexit:                             ; preds = %27
  br label %._crit_edge

._crit_edge:                                      ; preds = %._crit_edge.loopexit, %find_array_descriptor.exit
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define void @array_set_int(%struct.array_table* readonly %table, i64 %arrid, i64 %pos, i32 %val) #0 {
  %1 = alloca i32, align 4
  store i32 %val, i32* %1, align 4, !tbaa !16
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([55 x i8]* @.str17, i64 0, i64 0), i64 54, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 0
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = icmp ugt i64 %21, %pos
  br i1 %22, label %array_set_value.exit, label %23

; <label>:23                                      ; preds = %19
  %24 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %25 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %24, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %21) #4
  tail call void @exit(i32 1) #5
  unreachable

array_set_value.exit:                             ; preds = %19
  %26 = bitcast i32* %1 to i8*
  %27 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %28 = load i8** %27, align 8, !tbaa !10
  %29 = shl i64 %pos, 2
  %30 = getelementptr i8* %28, i64 %29
  %31 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %30, i1 false) #4
  %32 = call i8* @__memcpy_chk(i8* %30, i8* %26, i64 4, i64 %31) #4
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %array_set_value.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_set_float(%struct.array_table* readonly %table, i64 %arrid, i64 %pos, float %val) #0 {
  %1 = alloca float, align 4
  store float %val, float* %1, align 4, !tbaa !20
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([57 x i8]* @.str18, i64 0, i64 0), i64 56, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 1
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = icmp ugt i64 %21, %pos
  br i1 %22, label %array_set_value.exit, label %23

; <label>:23                                      ; preds = %19
  %24 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %25 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %24, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %21) #4
  tail call void @exit(i32 1) #5
  unreachable

array_set_value.exit:                             ; preds = %19
  %26 = bitcast float* %1 to i8*
  %27 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %28 = load i8** %27, align 8, !tbaa !10
  %29 = shl i64 %pos, 2
  %30 = getelementptr i8* %28, i64 %29
  %31 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %30, i1 false) #4
  %32 = call i8* @__memcpy_chk(i8* %30, i8* %26, i64 4, i64 %31) #4
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %array_set_value.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_set_bool(%struct.array_table* readonly %table, i64 %arrid, i64 %pos, i1 zeroext %val) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %val to i8
  store i8 %2, i8* %1, align 1, !tbaa !18
  %3 = icmp eq %struct.array_table* %table, null
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([56 x i8]* @.str19, i64 0, i64 0), i64 55, i64 1, %struct.__sFILE* %5)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %8, align 8
  %9 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %9, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %7
  br label %.lr.ph.i

; <label>:10                                      ; preds = %.lr.ph.i
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %11, align 8
  %12 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %12, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %10
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %10 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %13 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %14 = load i64* %13, align 8, !tbaa !12
  %15 = icmp eq i64 %14, %arrid
  br i1 %15, label %16, label %10

; <label>:16                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %18 = load i64* %17, align 8, !tbaa !15
  %19 = icmp eq i64 %18, 2
  br i1 %19, label %20, label %find_array_descriptor.exit.thread

; <label>:20                                      ; preds = %16
  %21 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %22 = load i64* %21, align 8, !tbaa !13
  %23 = icmp ugt i64 %22, %pos
  br i1 %23, label %array_set_value.exit, label %24

; <label>:24                                      ; preds = %20
  %25 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %26 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %25, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %22) #4
  tail call void @exit(i32 1) #5
  unreachable

array_set_value.exit:                             ; preds = %20
  %27 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %28 = load i8** %27, align 8, !tbaa !10
  %29 = getelementptr i8* %28, i64 %pos
  %30 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %29, i1 false) #4
  %31 = call i8* @__memcpy_chk(i8* %29, i8* %1, i64 1, i64 %30) #4
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %10
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %7, %16, %array_set_value.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_set_char(%struct.array_table* readonly %table, i64 %arrid, i64 %pos, i8 signext %val) #0 {
  %1 = alloca i8, align 1
  store i8 %val, i8* %1, align 1, !tbaa !22
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([56 x i8]* @.str20, i64 0, i64 0), i64 55, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 3
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = icmp ugt i64 %21, %pos
  br i1 %22, label %array_set_value.exit, label %23

; <label>:23                                      ; preds = %19
  %24 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %25 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %24, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %21) #4
  tail call void @exit(i32 1) #5
  unreachable

array_set_value.exit:                             ; preds = %19
  %26 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %27 = load i8** %26, align 8, !tbaa !10
  %28 = getelementptr i8* %27, i64 %pos
  %29 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %28, i1 false) #4
  %30 = call i8* @__memcpy_chk(i8* %28, i8* %1, i64 1, i64 %29) #4
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %array_set_value.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_set_string(%struct.array_table* readonly %table, i64 %arrid, i64 %pos, i64 %val) #0 {
  %1 = alloca i64, align 8
  store i64 %val, i64* %1, align 8, !tbaa !1
  %2 = icmp eq %struct.array_table* %table, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([58 x i8]* @.str21, i64 0, i64 0), i64 57, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %7, align 8
  %8 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %8, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %6
  br label %.lr.ph.i

; <label>:9                                       ; preds = %.lr.ph.i
  %10 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %10, align 8
  %11 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %11, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %9
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %9 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %13 = load i64* %12, align 8, !tbaa !12
  %14 = icmp eq i64 %13, %arrid
  br i1 %14, label %15, label %9

; <label>:15                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %17 = load i64* %16, align 8, !tbaa !15
  %18 = icmp eq i64 %17, 4
  br i1 %18, label %19, label %find_array_descriptor.exit.thread

; <label>:19                                      ; preds = %15
  %20 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %21 = load i64* %20, align 8, !tbaa !13
  %22 = icmp ugt i64 %21, %pos
  br i1 %22, label %array_set_value.exit, label %23

; <label>:23                                      ; preds = %19
  %24 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %25 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %24, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %21) #4
  tail call void @exit(i32 1) #5
  unreachable

array_set_value.exit:                             ; preds = %19
  %26 = bitcast i64* %1 to i8*
  %27 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %28 = load i8** %27, align 8, !tbaa !10
  %29 = shl i64 %pos, 3
  %30 = getelementptr i8* %28, i64 %29
  %31 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %30, i1 false) #4
  %32 = call i8* @__memcpy_chk(i8* %30, i8* %26, i64 8, i64 %31) #4
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread.loopexit:       ; preds = %9
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %6, %15, %array_set_value.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @string_get_char(%struct.array_table* readonly %table, i64 %arrid, i64 %pos) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %array_get_char.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %3, align 8
  %4 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %4, label %array_get_char.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %7, label %array_get_char.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %9 = load i64* %8, align 8, !tbaa !12
  %10 = icmp eq i64 %9, %arrid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 2
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 3
  br i1 %14, label %15, label %array_get_char.exit

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %17 = load i64* %16, align 8, !tbaa !13
  %18 = icmp ugt i64 %17, %pos
  br i1 %18, label %array_get_value.exit.i, label %19

; <label>:19                                      ; preds = %15
  %20 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %21 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %20, i8* getelementptr inbounds ([65 x i8]* @.str28, i64 0, i64 0), i64 %pos, i64 %17) #4
  tail call void @exit(i32 1) #5
  unreachable

array_get_value.exit.i:                           ; preds = %15
  %22 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %23 = load i8** %22, align 8, !tbaa !10
  %24 = getelementptr i8* %23, i64 %pos
  %25 = load i8* %24, align 1, !tbaa !22
  br label %array_get_char.exit

array_get_char.exit.loopexit:                     ; preds = %5
  br label %array_get_char.exit

array_get_char.exit:                              ; preds = %array_get_char.exit.loopexit, %0, %2, %11, %array_get_value.exit.i
  %.0.i = phi i8 [ %25, %array_get_value.exit.i ], [ 0, %0 ], [ 0, %11 ], [ 0, %2 ], [ 0, %array_get_char.exit.loopexit ]
  ret i8 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @string_concat(%struct.array_table* %table, i64 %arrid1, i64 %arrid2) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([55 x i8]* @.str22, i64 0, i64 0), i64 54, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit7.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %.lr.ph.i5.preheader, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid1
  br i1 %13, label %.lr.ph.i5.preheader, label %8

.lr.ph.i5.preheader:                              ; preds = %.lr.ph.i, %8
  %.0.i.ph = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ], [ null, %8 ]
  br label %.lr.ph.i5

; <label>:14                                      ; preds = %.lr.ph.i5
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i4, i64 0, i32 5
  %current.0.i3 = load %struct.array_descriptor** %15, align 8
  %16 = icmp eq %struct.array_descriptor* %current.0.i3, null
  br i1 %16, label %find_array_descriptor.exit7, label %.lr.ph.i5

.lr.ph.i5:                                        ; preds = %.lr.ph.i5.preheader, %14
  %current.02.i4 = phi %struct.array_descriptor* [ %current.0.i3, %14 ], [ %current.01.i, %.lr.ph.i5.preheader ]
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i4, i64 0, i32 0
  %18 = load i64* %17, align 8, !tbaa !12
  %19 = icmp eq i64 %18, %arrid2
  br i1 %19, label %find_array_descriptor.exit7, label %14

find_array_descriptor.exit7:                      ; preds = %14, %.lr.ph.i5
  %.0.i6.ph = phi %struct.array_descriptor* [ %current.02.i4, %.lr.ph.i5 ], [ null, %14 ]
  %20 = icmp eq %struct.array_descriptor* %.0.i.ph, null
  br i1 %20, label %find_array_descriptor.exit7.thread, label %21

; <label>:21                                      ; preds = %find_array_descriptor.exit7
  %22 = getelementptr inbounds %struct.array_descriptor* %.0.i.ph, i64 0, i32 2
  %23 = load i64* %22, align 8, !tbaa !15
  %24 = icmp eq i64 %23, 3
  %25 = icmp ne %struct.array_descriptor* %.0.i6.ph, null
  %or.cond = and i1 %24, %25
  br i1 %or.cond, label %26, label %find_array_descriptor.exit7.thread

; <label>:26                                      ; preds = %21
  %27 = getelementptr inbounds %struct.array_descriptor* %.0.i6.ph, i64 0, i32 2
  %28 = load i64* %27, align 8, !tbaa !15
  %29 = icmp eq i64 %28, 3
  br i1 %29, label %array_allocate_char.exit, label %find_array_descriptor.exit7.thread

find_array_descriptor.exit7.thread:               ; preds = %5, %26, %find_array_descriptor.exit7, %21
  %30 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %31 = tail call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @.str23, i64 0, i64 0), i64 44, i64 1, %struct.__sFILE* %30)
  tail call void @exit(i32 1) #5
  unreachable

array_allocate_char.exit:                         ; preds = %26
  %32 = getelementptr inbounds %struct.array_descriptor* %.0.i.ph, i64 0, i32 1
  %33 = load i64* %32, align 8, !tbaa !13
  %34 = getelementptr inbounds %struct.array_descriptor* %.0.i.ph, i64 0, i32 3
  %35 = load i8** %34, align 8, !tbaa !10
  %36 = load i64* @array_counter, align 8, !tbaa !1
  %37 = add i64 %36, 1
  store i64 %37, i64* @array_counter, align 8, !tbaa !1
  %38 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %36, i64 %33, i64 3) #4
  %39 = load %struct.array_descriptor** %6, align 8, !tbaa !5
  %40 = getelementptr inbounds %struct.array_descriptor* %38, i64 0, i32 5
  store %struct.array_descriptor* %39, %struct.array_descriptor** %40, align 8, !tbaa !8
  store %struct.array_descriptor* %38, %struct.array_descriptor** %6, align 8, !tbaa !5
  %41 = getelementptr inbounds %struct.array_descriptor* %38, i64 0, i32 3
  %42 = load i8** %41, align 8, !tbaa !10
  %43 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %42, i1 false) #4
  %44 = tail call i8* @__memcpy_chk(i8* %42, i8* %35, i64 %33, i64 %43) #4
  %current.01.i8.pre = load %struct.array_descriptor** %6, align 8
  %45 = icmp eq %struct.array_descriptor* %current.01.i8.pre, null
  br i1 %45, label %find_array_descriptor.exit13, label %.lr.ph.i11.preheader

.lr.ph.i11.preheader:                             ; preds = %array_allocate_char.exit
  br label %.lr.ph.i11

; <label>:46                                      ; preds = %.lr.ph.i11
  %47 = getelementptr inbounds %struct.array_descriptor* %current.02.i10, i64 0, i32 5
  %current.0.i9 = load %struct.array_descriptor** %47, align 8
  %48 = icmp eq %struct.array_descriptor* %current.0.i9, null
  br i1 %48, label %find_array_descriptor.exit13.loopexit, label %.lr.ph.i11

.lr.ph.i11:                                       ; preds = %.lr.ph.i11.preheader, %46
  %current.02.i10 = phi %struct.array_descriptor* [ %current.0.i9, %46 ], [ %current.01.i8.pre, %.lr.ph.i11.preheader ]
  %49 = getelementptr inbounds %struct.array_descriptor* %current.02.i10, i64 0, i32 0
  %50 = load i64* %49, align 8, !tbaa !12
  %51 = icmp eq i64 %50, %36
  br i1 %51, label %find_array_descriptor.exit13.loopexit, label %46

find_array_descriptor.exit13.loopexit:            ; preds = %.lr.ph.i11, %46
  %.0.i12.ph = phi %struct.array_descriptor* [ %current.02.i10, %.lr.ph.i11 ], [ null, %46 ]
  br label %find_array_descriptor.exit13

find_array_descriptor.exit13:                     ; preds = %find_array_descriptor.exit13.loopexit, %array_allocate_char.exit
  %.0.i12 = phi %struct.array_descriptor* [ null, %array_allocate_char.exit ], [ %.0.i12.ph, %find_array_descriptor.exit13.loopexit ]
  %52 = getelementptr inbounds %struct.array_descriptor* %.0.i6.ph, i64 0, i32 1
  %53 = load i64* %52, align 8, !tbaa !13
  %54 = icmp eq i64 %53, 0
  br i1 %54, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %find_array_descriptor.exit13
  %55 = getelementptr inbounds %struct.array_descriptor* %.0.i12, i64 0, i32 1
  %56 = getelementptr inbounds %struct.array_descriptor* %.0.i12, i64 0, i32 3
  br label %57

; <label>:57                                      ; preds = %.lr.ph, %57
  %i.016 = phi i64 [ 0, %.lr.ph ], [ %61, %57 ]
  %58 = load i64* %55, align 8, !tbaa !13
  %59 = load i8** %56, align 8, !tbaa !10
  %60 = getelementptr inbounds i8* %59, i64 %i.016
  tail call fastcc void @array_insert_value(%struct.array_descriptor* %.0.i12, i64 %58, i8* %60)
  %61 = add i64 %i.016, 1
  %62 = load i64* %52, align 8, !tbaa !13
  %63 = icmp ult i64 %61, %62
  br i1 %63, label %57, label %._crit_edge.loopexit

._crit_edge.loopexit:                             ; preds = %57
  br label %._crit_edge

._crit_edge:                                      ; preds = %._crit_edge.loopexit, %find_array_descriptor.exit13
  ret i64 %36
}

; Function Attrs: nounwind ssp uwtable
define void @print_string(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([54 x i8]* @.str24, i64 0, i64 0), i64 53, i64 1, %struct.__sFILE* %3)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i, null
  br i1 %7, label %find_array_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %5
  br label %.lr.ph.i

; <label>:8                                       ; preds = %.lr.ph.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %10, label %find_array_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %8
  %current.02.i = phi %struct.array_descriptor* [ %current.0.i, %8 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.array_descriptor* [ %current.02.i, %.lr.ph.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 2
  %16 = load i64* %15, align 8, !tbaa !15
  %17 = icmp eq i64 %16, 3
  br i1 %17, label %.preheader, label %find_array_descriptor.exit.thread

.preheader:                                       ; preds = %14
  %18 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 1
  %19 = load i64* %18, align 8, !tbaa !13
  %20 = icmp eq i64 %19, 0
  br i1 %20, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %.preheader
  %21 = getelementptr inbounds %struct.array_descriptor* %current.02.i.lcssa, i64 0, i32 3
  br label %24

find_array_descriptor.exit.thread.loopexit:       ; preds = %8
  br label %find_array_descriptor.exit.thread

find_array_descriptor.exit.thread:                ; preds = %find_array_descriptor.exit.thread.loopexit, %5, %14
  %22 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %23 = tail call i64 @fwrite(i8* getelementptr inbounds ([44 x i8]* @.str25, i64 0, i64 0), i64 43, i64 1, %struct.__sFILE* %22)
  tail call void @exit(i32 1) #5
  unreachable

; <label>:24                                      ; preds = %.lr.ph, %24
  %i.04 = phi i64 [ 0, %.lr.ph ], [ %29, %24 ]
  %25 = load i8** %21, align 8, !tbaa !10
  %26 = getelementptr inbounds i8* %25, i64 %i.04
  %27 = load i8* %26, align 1, !tbaa !22
  %28 = sext i8 %27 to i32
  %putchar = tail call i32 @putchar(i32 %28) #4
  %29 = add i64 %i.04, 1
  %30 = load i64* %18, align 8, !tbaa !13
  %31 = icmp ult i64 %29, %30
  br i1 %31, label %24, label %._crit_edge.loopexit

._crit_edge.loopexit:                             ; preds = %24
  br label %._crit_edge

._crit_edge:                                      ; preds = %._crit_edge.loopexit, %.preheader
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i64 @string_len(%struct.array_table* readonly %table, i64 %arrid) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i.i, null
  br i1 %7, label %array_size_char.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %5
  br label %.lr.ph.i.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %10, label %array_size_char.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %8
  %current.02.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %8 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %arrid
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %array_size_char.exit

array_size_char.exit.loopexit:                    ; preds = %8
  br label %array_size_char.exit

array_size_char.exit:                             ; preds = %array_size_char.exit.loopexit, %5, %14
  %.0.i.i = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %array_size_char.exit.loopexit ]
  ret i64 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_size_char(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %array_size.exit

array_size.exit.loopexit:                         ; preds = %8
  br label %array_size.exit

array_size.exit:                                  ; preds = %array_size.exit.loopexit, %5, %14
  %.0.i = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %array_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define void @println_string(%struct.array_table* readonly %table, i64 %arrid) #0 {
  tail call void @print_string(%struct.array_table* %table, i64 %arrid)
  %putchar = tail call i32 @putchar(i32 10) #4
  ret void
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_empty_int(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i.i, null
  br i1 %7, label %array_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %5
  br label %.lr.ph.i.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %10, label %array_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %8
  %current.02.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %8 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  %phitmp.i = icmp eq i64 %16, 0
  br label %array_empty.exit

array_empty.exit.loopexit:                        ; preds = %8
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %array_empty.exit.loopexit, %5, %14
  %.0.i.i = phi i1 [ %phitmp.i, %14 ], [ true, %5 ], [ true, %array_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_empty_float(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i.i, null
  br i1 %7, label %array_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %5
  br label %.lr.ph.i.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %10, label %array_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %8
  %current.02.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %8 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  %phitmp.i = icmp eq i64 %16, 0
  br label %array_empty.exit

array_empty.exit.loopexit:                        ; preds = %8
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %array_empty.exit.loopexit, %5, %14
  %.0.i.i = phi i1 [ %phitmp.i, %14 ], [ true, %5 ], [ true, %array_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_empty_double(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i.i, null
  br i1 %7, label %array_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %5
  br label %.lr.ph.i.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %10, label %array_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %8
  %current.02.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %8 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  %phitmp.i = icmp eq i64 %16, 0
  br label %array_empty.exit

array_empty.exit.loopexit:                        ; preds = %8
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %array_empty.exit.loopexit, %5, %14
  %.0.i.i = phi i1 [ %phitmp.i, %14 ], [ true, %5 ], [ true, %array_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_empty_char(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i.i, null
  br i1 %7, label %array_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %5
  br label %.lr.ph.i.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %10, label %array_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %8
  %current.02.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %8 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  %phitmp.i = icmp eq i64 %16, 0
  br label %array_empty.exit

array_empty.exit.loopexit:                        ; preds = %8
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %array_empty.exit.loopexit, %5, %14
  %.0.i.i = phi i1 [ %phitmp.i, %14 ], [ true, %5 ], [ true, %array_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @array_empty_string(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i.i, null
  br i1 %7, label %array_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %5
  br label %.lr.ph.i.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %10, label %array_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %8
  %current.02.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %8 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  %phitmp.i = icmp eq i64 %16, 0
  br label %array_empty.exit

array_empty.exit.loopexit:                        ; preds = %8
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %array_empty.exit.loopexit, %5, %14
  %.0.i.i = phi i1 [ %phitmp.i, %14 ], [ true, %5 ], [ true, %array_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_size_int(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %array_size.exit

array_size.exit.loopexit:                         ; preds = %8
  br label %array_size.exit

array_size.exit:                                  ; preds = %array_size.exit.loopexit, %5, %14
  %.0.i = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %array_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_size_float(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %array_size.exit

array_size.exit.loopexit:                         ; preds = %8
  br label %array_size.exit

array_size.exit:                                  ; preds = %array_size.exit.loopexit, %5, %14
  %.0.i = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %array_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_size_double(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %array_size.exit

array_size.exit.loopexit:                         ; preds = %8
  br label %array_size.exit

array_size.exit:                                  ; preds = %array_size.exit.loopexit, %5, %14
  %.0.i = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %array_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define i64 @array_size_string(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([52 x i8]* @.str2, i64 0, i64 0), i64 51, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  %16 = load i64* %15, align 8, !tbaa !13
  br label %array_size.exit

array_size.exit.loopexit:                         ; preds = %8
  br label %array_size.exit

array_size.exit:                                  ; preds = %array_size.exit.loopexit, %5, %14
  %.0.i = phi i64 [ %16, %14 ], [ 0, %5 ], [ 0, %array_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define void @array_clear_int(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str9, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %16 = load i8** %15, align 8, !tbaa !10
  tail call void @free(i8* %16) #4
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store i64 0, i64* %17, align 8, !tbaa !13
  store i8* null, i8** %15, align 8, !tbaa !10
  br label %array_clear.exit

array_clear.exit.loopexit:                        ; preds = %8
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %array_clear.exit.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_clear_float(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str9, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %16 = load i8** %15, align 8, !tbaa !10
  tail call void @free(i8* %16) #4
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store i64 0, i64* %17, align 8, !tbaa !13
  store i8* null, i8** %15, align 8, !tbaa !10
  br label %array_clear.exit

array_clear.exit.loopexit:                        ; preds = %8
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %array_clear.exit.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_clear_double(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str9, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %16 = load i8** %15, align 8, !tbaa !10
  tail call void @free(i8* %16) #4
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store i64 0, i64* %17, align 8, !tbaa !13
  store i8* null, i8** %15, align 8, !tbaa !10
  br label %array_clear.exit

array_clear.exit.loopexit:                        ; preds = %8
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %array_clear.exit.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_clear_char(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str9, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %16 = load i8** %15, align 8, !tbaa !10
  tail call void @free(i8* %16) #4
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store i64 0, i64* %17, align 8, !tbaa !13
  store i8* null, i8** %15, align 8, !tbaa !10
  br label %array_clear.exit

array_clear.exit.loopexit:                        ; preds = %8
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %array_clear.exit.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @array_clear_string(%struct.array_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.array_table* %table, null
  br i1 %1, label %2, label %5

; <label>:2                                       ; preds = %0
  %3 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !11
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str9, i64 0, i64 0), i64 52, i64 1, %struct.__sFILE* %3) #4
  tail call void @exit(i32 1) #5
  unreachable

; <label>:5                                       ; preds = %0
  %6 = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.array_descriptor** %6, align 8
  %7 = icmp eq %struct.array_descriptor* %current.01.i.i, null
  br i1 %7, label %array_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %5
  br label %.lr.ph.i.i

; <label>:8                                       ; preds = %.lr.ph.i.i
  %9 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %9, align 8
  %10 = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %10, label %array_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %8
  %current.02.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %8 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %11 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i, i64 0, i32 0
  %12 = load i64* %11, align 8, !tbaa !12
  %13 = icmp eq i64 %12, %id
  br i1 %13, label %14, label %8

; <label>:14                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.array_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %15 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %16 = load i8** %15, align 8, !tbaa !10
  tail call void @free(i8* %16) #4
  %17 = getelementptr inbounds %struct.array_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store i64 0, i64* %17, align 8, !tbaa !13
  store i8* null, i8** %15, align 8, !tbaa !10
  br label %array_clear.exit

array_clear.exit.loopexit:                        ; preds = %8
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %array_clear.exit.loopexit, %5, %14
  ret void
}

; Function Attrs: nounwind
declare i8* @__memmove_chk(i8*, i8*, i64, i64) #1

; Function Attrs: nounwind
declare noalias i8* @realloc(i8* nocapture, i64) #1

; Function Attrs: nounwind
declare i64 @fwrite(i8* nocapture, i64, i64, %struct.__sFILE* nocapture) #4

; Function Attrs: nounwind
declare i32 @putchar(i32) #4

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.uadd.with.overflow.i64(i64, i64) #2

; Function Attrs: nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #4

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone }
attributes #3 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.1.0 (clang-602.0.49) (based on LLVM 3.6.0svn)"}
!1 = metadata !{metadata !2, metadata !2, i64 0}
!2 = metadata !{metadata !"long", metadata !3, i64 0}
!3 = metadata !{metadata !"omnipotent char", metadata !4, i64 0}
!4 = metadata !{metadata !"Simple C/C++ TBAA"}
!5 = metadata !{metadata !6, metadata !7, i64 0}
!6 = metadata !{metadata !"array_table", metadata !7, i64 0}
!7 = metadata !{metadata !"any pointer", metadata !3, i64 0}
!8 = metadata !{metadata !9, metadata !7, i64 40}
!9 = metadata !{metadata !"array_descriptor", metadata !2, i64 0, metadata !2, i64 8, metadata !2, i64 16, metadata !7, i64 24, metadata !2, i64 32, metadata !7, i64 40}
!10 = metadata !{metadata !9, metadata !7, i64 24}
!11 = metadata !{metadata !7, metadata !7, i64 0}
!12 = metadata !{metadata !9, metadata !2, i64 0}
!13 = metadata !{metadata !9, metadata !2, i64 8}
!14 = metadata !{metadata !9, metadata !2, i64 32}
!15 = metadata !{metadata !9, metadata !2, i64 16}
!16 = metadata !{metadata !17, metadata !17, i64 0}
!17 = metadata !{metadata !"int", metadata !3, i64 0}
!18 = metadata !{metadata !19, metadata !19, i64 0}
!19 = metadata !{metadata !"_Bool", metadata !3, i64 0}
!20 = metadata !{metadata !21, metadata !21, i64 0}
!21 = metadata !{metadata !"float", metadata !3, i64 0}
!22 = metadata !{metadata !3, metadata !3, i64 0}
!23 = metadata !{i8 0, i8 2}
