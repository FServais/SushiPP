; ModuleID = 'runtime/list_runtime.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.10.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%struct.list_table = type { %struct.list_descriptor* }
%struct.list_descriptor = type { %struct.node_t*, %struct.node_t*, i64, i64, i64, i64, %struct.list_descriptor* }
%struct.node_t = type { i8*, %struct.node_t*, %struct.node_t* }

@__stderrp = external global %struct.__sFILE*
@.str = private unnamed_addr constant [50 x i8] c"Memory allocation failure in `create_list_table`\0A\00", align 1
@.str1 = private unnamed_addr constant [69 x i8] c"List node number `%zu` out of bounds (list contains %zu element(s))\0A\00", align 1
@.str2 = private unnamed_addr constant [44 x i8] c"Memory allocation failure in `create_node`\0A\00", align 1
@.str3 = private unnamed_addr constant [42 x i8] c"Memory allocation failure in `cpy_value`\0A\00", align 1
@bytes_per_type = internal unnamed_addr constant [5 x i64] [i64 4, i64 4, i64 1, i64 1, i64 8], align 16
@list_counter = internal unnamed_addr global i64 1, align 8
@.str4 = private unnamed_addr constant [50 x i8] c"Memory allocation failure in `create_descriptor`\0A\00", align 1

; Function Attrs: nounwind ssp uwtable
define noalias %struct.list_table* @create_list_table() #0 {
  %1 = tail call i8* @malloc(i64 8) #5
  %2 = icmp eq i8* %1, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #6
  unreachable

; <label>:6                                       ; preds = %0
  %7 = bitcast i8* %1 to %struct.list_table*
  %8 = bitcast i8* %1 to %struct.list_descriptor**
  store %struct.list_descriptor* null, %struct.list_descriptor** %8, align 8, !tbaa !5
  ret %struct.list_table* %7
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
declare i32 @fprintf(%struct.__sFILE* nocapture, i8* nocapture readonly, ...) #1

; Function Attrs: noreturn
declare void @exit(i32) #2

; Function Attrs: nounwind ssp uwtable
define void @delete_list_table(%struct.list_table* %table) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %20, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %4 = load %struct.list_descriptor** %3, align 8, !tbaa !5
  %5 = icmp eq %struct.list_descriptor* %4, null
  br i1 %5, label %._crit_edge, label %.lr.ph.preheader

.lr.ph.preheader:                                 ; preds = %2
  br label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph.preheader, %free_descriptor.exit
  %current.01 = phi %struct.list_descriptor* [ %7, %free_descriptor.exit ], [ %4, %.lr.ph.preheader ]
  %6 = getelementptr inbounds %struct.list_descriptor* %current.01, i64 0, i32 6
  %7 = load %struct.list_descriptor** %6, align 8, !tbaa !7
  %8 = getelementptr inbounds %struct.list_descriptor* %current.01, i64 0, i32 0
  %9 = load %struct.node_t** %8, align 8, !tbaa !10
  %10 = icmp eq %struct.node_t* %9, null
  br i1 %10, label %free_descriptor.exit, label %free_node.exit.i.preheader

free_node.exit.i.preheader:                       ; preds = %.lr.ph
  br label %free_node.exit.i

free_node.exit.i:                                 ; preds = %free_node.exit.i.preheader, %free_node.exit.i
  %current.01.i = phi %struct.node_t* [ %12, %free_node.exit.i ], [ %9, %free_node.exit.i.preheader ]
  %11 = getelementptr inbounds %struct.node_t* %current.01.i, i64 0, i32 1
  %12 = load %struct.node_t** %11, align 8, !tbaa !11
  %13 = getelementptr inbounds %struct.node_t* %current.01.i, i64 0, i32 0
  %14 = load i8** %13, align 8, !tbaa !13
  tail call void @free(i8* %14) #5
  %15 = bitcast %struct.node_t* %current.01.i to i8*
  tail call void @free(i8* %15) #5
  %16 = icmp eq %struct.node_t* %12, null
  br i1 %16, label %free_descriptor.exit.loopexit, label %free_node.exit.i

free_descriptor.exit.loopexit:                    ; preds = %free_node.exit.i
  br label %free_descriptor.exit

free_descriptor.exit:                             ; preds = %free_descriptor.exit.loopexit, %.lr.ph
  %17 = bitcast %struct.list_descriptor* %current.01 to i8*
  tail call void @free(i8* %17) #5
  %18 = icmp eq %struct.list_descriptor* %7, null
  br i1 %18, label %._crit_edge.loopexit, label %.lr.ph

._crit_edge.loopexit:                             ; preds = %free_descriptor.exit
  br label %._crit_edge

._crit_edge:                                      ; preds = %._crit_edge.loopexit, %2
  %19 = bitcast %struct.list_table* %table to i8*
  tail call void @free(i8* %19)
  br label %20

; <label>:20                                      ; preds = %0, %._crit_edge
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #1

; Function Attrs: nounwind readonly ssp uwtable
define i64 @list_size(%struct.list_table* readonly %table, i64 %lid) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i64 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind readonly ssp uwtable
define zeroext i1 @list_empty(%struct.list_table* readonly %table, i64 %lid) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_size.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %phitmp = icmp eq i64 %13, 0
  br label %list_size.exit

list_size.exit.loopexit:                          ; preds = %5
  br label %list_size.exit

list_size.exit:                                   ; preds = %list_size.exit.loopexit, %0, %2, %11
  %.0.i = phi i1 [ %phitmp, %11 ], [ true, %0 ], [ true, %2 ], [ true, %list_size.exit.loopexit ]
  ret i1 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define void @list_clear(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %13 = load %struct.node_t** %12, align 8, !tbaa !10
  %14 = icmp eq %struct.node_t* %13, null
  br i1 %14, label %find_descriptor.exit.thread, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.node_t* %13, i64 0, i32 2
  %17 = load %struct.node_t** %16, align 8, !tbaa !16
  %18 = icmp eq %struct.node_t* %17, null
  br i1 %18, label %free_node.exit.i.preheader, label %.preheader.i

.preheader.i:                                     ; preds = %15
  %19 = getelementptr inbounds %struct.node_t* %17, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %19, align 8, !tbaa !11
  br label %free_node.exit.i.preheader

free_node.exit.i.preheader:                       ; preds = %15, %.preheader.i
  br label %free_node.exit.i

free_node.exit.i:                                 ; preds = %free_node.exit.i.preheader, %free_node.exit.i
  %.01.i = phi %struct.node_t* [ %21, %free_node.exit.i ], [ %13, %free_node.exit.i.preheader ]
  %20 = getelementptr inbounds %struct.node_t* %.01.i, i64 0, i32 1
  %21 = load %struct.node_t** %20, align 8, !tbaa !11
  %22 = getelementptr inbounds %struct.node_t* %.01.i, i64 0, i32 0
  %23 = load i8** %22, align 8, !tbaa !13
  tail call void @free(i8* %23) #5
  %24 = bitcast %struct.node_t* %.01.i to i8*
  tail call void @free(i8* %24) #5
  %25 = icmp eq %struct.node_t* %21, null
  br i1 %25, label %free_node_recur.exit, label %free_node.exit.i

free_node_recur.exit:                             ; preds = %free_node.exit.i
  %26 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 1
  store %struct.node_t* %17, %struct.node_t** %26, align 8, !tbaa !17
  store %struct.node_t* %17, %struct.node_t** %12, align 8, !tbaa !10
  %27 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  store i64 0, i64* %27, align 8, !tbaa !15
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %11, %0, %free_node_recur.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_add_reference(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 4
  %13 = load i64* %12, align 8, !tbaa !18
  %14 = add i64 %13, 1
  store i64 %14, i64* %12, align 8, !tbaa !18
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_rm_reference(%struct.list_table* %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_deallocate.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %list_deallocate.exit, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %list_deallocate.exit.loopexit16, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 4
  %13 = load i64* %12, align 8, !tbaa !18
  %14 = add i64 %13, -1
  store i64 %14, i64* %12, align 8, !tbaa !18
  %.not = icmp eq i64 %14, 0
  br i1 %.not, label %15, label %list_deallocate.exit

; <label>:15                                      ; preds = %11
  %current.03.i = load %struct.list_descriptor** %3, align 8
  %16 = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %16, label %list_deallocate.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %15
  br label %.lr.ph.i2

; <label>:17                                      ; preds = %.lr.ph.i2
  %18 = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i1 = load %struct.list_descriptor** %18, align 8
  %19 = icmp eq %struct.list_descriptor* %current.0.i1, null
  br i1 %19, label %list_deallocate.exit.loopexit, label %.lr.ph.i2

.lr.ph.i2:                                        ; preds = %.lr.ph.i2.preheader, %17
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i1, %17 ], [ %current.03.i, %.lr.ph.i2.preheader ]
  %prev.04.i = phi %struct.list_descriptor* [ %current.05.i, %17 ], [ null, %.lr.ph.i2.preheader ]
  %20 = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %21 = load i64* %20, align 8, !tbaa !14
  %22 = icmp eq i64 %21, %lid
  br i1 %22, label %23, label %17

; <label>:23                                      ; preds = %.lr.ph.i2
  %prev.04.i.lcssa = phi %struct.list_descriptor* [ %prev.04.i, %.lr.ph.i2 ]
  %current.05.i.lcssa = phi %struct.list_descriptor* [ %current.05.i, %.lr.ph.i2 ]
  %24 = icmp eq %struct.list_descriptor* %prev.04.i.lcssa, null
  %25 = getelementptr inbounds %struct.list_descriptor* %current.05.i.lcssa, i64 0, i32 6
  %26 = load %struct.list_descriptor** %25, align 8, !tbaa !7
  br i1 %24, label %29, label %27

; <label>:27                                      ; preds = %23
  %28 = getelementptr inbounds %struct.list_descriptor* %prev.04.i.lcssa, i64 0, i32 6
  store %struct.list_descriptor* %26, %struct.list_descriptor** %28, align 8, !tbaa !7
  br label %30

; <label>:29                                      ; preds = %23
  store %struct.list_descriptor* %26, %struct.list_descriptor** %3, align 8, !tbaa !5
  br label %30

; <label>:30                                      ; preds = %29, %27
  %31 = getelementptr inbounds %struct.list_descriptor* %current.05.i.lcssa, i64 0, i32 0
  %32 = load %struct.node_t** %31, align 8, !tbaa !10
  %33 = icmp eq %struct.node_t* %32, null
  br i1 %33, label %free_descriptor.exit.i, label %free_node.exit.i.i.preheader

free_node.exit.i.i.preheader:                     ; preds = %30
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %free_node.exit.i.i.preheader, %free_node.exit.i.i
  %current.01.i.i = phi %struct.node_t* [ %35, %free_node.exit.i.i ], [ %32, %free_node.exit.i.i.preheader ]
  %34 = getelementptr inbounds %struct.node_t* %current.01.i.i, i64 0, i32 1
  %35 = load %struct.node_t** %34, align 8, !tbaa !11
  %36 = getelementptr inbounds %struct.node_t* %current.01.i.i, i64 0, i32 0
  %37 = load i8** %36, align 8, !tbaa !13
  tail call void @free(i8* %37) #5
  %38 = bitcast %struct.node_t* %current.01.i.i to i8*
  tail call void @free(i8* %38) #5
  %39 = icmp eq %struct.node_t* %35, null
  br i1 %39, label %free_descriptor.exit.i.loopexit, label %free_node.exit.i.i

free_descriptor.exit.i.loopexit:                  ; preds = %free_node.exit.i.i
  br label %free_descriptor.exit.i

free_descriptor.exit.i:                           ; preds = %free_descriptor.exit.i.loopexit, %30
  %40 = bitcast %struct.list_descriptor* %current.05.i.lcssa to i8*
  tail call void @free(i8* %40) #5
  br label %list_deallocate.exit

list_deallocate.exit.loopexit:                    ; preds = %17
  br label %list_deallocate.exit

list_deallocate.exit.loopexit16:                  ; preds = %5
  br label %list_deallocate.exit

list_deallocate.exit:                             ; preds = %list_deallocate.exit.loopexit16, %list_deallocate.exit.loopexit, %11, %2, %free_descriptor.exit.i, %15, %0
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_deallocate(%struct.list_table* %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %.loopexit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03 = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.03, null
  br i1 %4, label %.loopexit, label %.lr.ph.preheader

.lr.ph.preheader:                                 ; preds = %2
  br label %.lr.ph

; <label>:5                                       ; preds = %.lr.ph
  %6 = getelementptr inbounds %struct.list_descriptor* %current.05, i64 0, i32 6
  %current.0 = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0, null
  br i1 %7, label %.loopexit.loopexit, label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph.preheader, %5
  %current.05 = phi %struct.list_descriptor* [ %current.0, %5 ], [ %current.03, %.lr.ph.preheader ]
  %prev.04 = phi %struct.list_descriptor* [ %current.05, %5 ], [ null, %.lr.ph.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.05, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph
  %prev.04.lcssa = phi %struct.list_descriptor* [ %prev.04, %.lr.ph ]
  %current.05.lcssa = phi %struct.list_descriptor* [ %current.05, %.lr.ph ]
  %12 = icmp eq %struct.list_descriptor* %prev.04.lcssa, null
  %13 = getelementptr inbounds %struct.list_descriptor* %current.05.lcssa, i64 0, i32 6
  %14 = load %struct.list_descriptor** %13, align 8, !tbaa !7
  br i1 %12, label %17, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.list_descriptor* %prev.04.lcssa, i64 0, i32 6
  store %struct.list_descriptor* %14, %struct.list_descriptor** %16, align 8, !tbaa !7
  br label %18

; <label>:17                                      ; preds = %11
  store %struct.list_descriptor* %14, %struct.list_descriptor** %3, align 8, !tbaa !5
  br label %18

; <label>:18                                      ; preds = %17, %15
  %19 = getelementptr inbounds %struct.list_descriptor* %current.05.lcssa, i64 0, i32 0
  %20 = load %struct.node_t** %19, align 8, !tbaa !10
  %21 = icmp eq %struct.node_t* %20, null
  br i1 %21, label %free_descriptor.exit, label %free_node.exit.i.preheader

free_node.exit.i.preheader:                       ; preds = %18
  br label %free_node.exit.i

free_node.exit.i:                                 ; preds = %free_node.exit.i.preheader, %free_node.exit.i
  %current.01.i = phi %struct.node_t* [ %23, %free_node.exit.i ], [ %20, %free_node.exit.i.preheader ]
  %22 = getelementptr inbounds %struct.node_t* %current.01.i, i64 0, i32 1
  %23 = load %struct.node_t** %22, align 8, !tbaa !11
  %24 = getelementptr inbounds %struct.node_t* %current.01.i, i64 0, i32 0
  %25 = load i8** %24, align 8, !tbaa !13
  tail call void @free(i8* %25) #5
  %26 = bitcast %struct.node_t* %current.01.i to i8*
  tail call void @free(i8* %26) #5
  %27 = icmp eq %struct.node_t* %23, null
  br i1 %27, label %free_descriptor.exit.loopexit, label %free_node.exit.i

free_descriptor.exit.loopexit:                    ; preds = %free_node.exit.i
  br label %free_descriptor.exit

free_descriptor.exit:                             ; preds = %free_descriptor.exit.loopexit, %18
  %28 = bitcast %struct.list_descriptor* %current.05.lcssa to i8*
  tail call void @free(i8* %28) #5
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %5
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %2, %0, %free_descriptor.exit
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_allocate_int(%struct.list_table* %table) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %18, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @list_counter, align 8, !tbaa !19
  %4 = add i64 %3, 1
  store i64 %4, i64* @list_counter, align 8, !tbaa !19
  %5 = tail call i8* @malloc(i64 56) #5
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %create_descriptor.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str4, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %8) #5
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %2
  %10 = bitcast i8* %5 to %struct.list_descriptor*
  %11 = getelementptr inbounds i8* %5, i64 16
  %12 = bitcast i8* %11 to i64*
  store i64 %3, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %5, i64 24
  %14 = getelementptr inbounds i8* %5, i64 48
  %15 = bitcast i8* %14 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %5, i8 0, i64 16, i32 8, i1 false) #5
  %16 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  call void @llvm.memset.p0i8.i64(i8* %13, i8 0, i64 24, i32 8, i1 false)
  %17 = load %struct.list_descriptor** %16, align 8, !tbaa !5
  store %struct.list_descriptor* %17, %struct.list_descriptor** %15, align 8, !tbaa !7
  store %struct.list_descriptor* %10, %struct.list_descriptor** %16, align 8, !tbaa !5
  br label %18

; <label>:18                                      ; preds = %0, %create_descriptor.exit
  %.0 = phi i64 [ %3, %create_descriptor.exit ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_allocate_float(%struct.list_table* %table) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %20, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @list_counter, align 8, !tbaa !19
  %4 = add i64 %3, 1
  store i64 %4, i64* @list_counter, align 8, !tbaa !19
  %5 = tail call i8* @malloc(i64 56) #5
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %create_descriptor.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str4, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %8) #5
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %2
  %10 = bitcast i8* %5 to %struct.list_descriptor*
  %11 = getelementptr inbounds i8* %5, i64 16
  %12 = bitcast i8* %11 to i64*
  store i64 %3, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %5, i64 40
  %14 = bitcast i8* %13 to i64*
  store i64 1, i64* %14, align 8, !tbaa !20
  %15 = getelementptr inbounds i8* %5, i64 24
  %16 = getelementptr inbounds i8* %5, i64 48
  %17 = bitcast i8* %16 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %5, i8 0, i64 16, i32 8, i1 false) #5
  tail call void @llvm.memset.p0i8.i64(i8* %15, i8 0, i64 16, i32 8, i1 false) #5
  %18 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %19 = load %struct.list_descriptor** %18, align 8, !tbaa !5
  store %struct.list_descriptor* %19, %struct.list_descriptor** %17, align 8, !tbaa !7
  store %struct.list_descriptor* %10, %struct.list_descriptor** %18, align 8, !tbaa !5
  br label %20

; <label>:20                                      ; preds = %0, %create_descriptor.exit
  %.0 = phi i64 [ %3, %create_descriptor.exit ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_allocate_bool(%struct.list_table* %table) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %20, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @list_counter, align 8, !tbaa !19
  %4 = add i64 %3, 1
  store i64 %4, i64* @list_counter, align 8, !tbaa !19
  %5 = tail call i8* @malloc(i64 56) #5
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %create_descriptor.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str4, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %8) #5
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %2
  %10 = bitcast i8* %5 to %struct.list_descriptor*
  %11 = getelementptr inbounds i8* %5, i64 16
  %12 = bitcast i8* %11 to i64*
  store i64 %3, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %5, i64 40
  %14 = bitcast i8* %13 to i64*
  store i64 2, i64* %14, align 8, !tbaa !20
  %15 = getelementptr inbounds i8* %5, i64 24
  %16 = getelementptr inbounds i8* %5, i64 48
  %17 = bitcast i8* %16 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %5, i8 0, i64 16, i32 8, i1 false) #5
  tail call void @llvm.memset.p0i8.i64(i8* %15, i8 0, i64 16, i32 8, i1 false) #5
  %18 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %19 = load %struct.list_descriptor** %18, align 8, !tbaa !5
  store %struct.list_descriptor* %19, %struct.list_descriptor** %17, align 8, !tbaa !7
  store %struct.list_descriptor* %10, %struct.list_descriptor** %18, align 8, !tbaa !5
  br label %20

; <label>:20                                      ; preds = %0, %create_descriptor.exit
  %.0 = phi i64 [ %3, %create_descriptor.exit ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_allocate_char(%struct.list_table* %table) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %20, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @list_counter, align 8, !tbaa !19
  %4 = add i64 %3, 1
  store i64 %4, i64* @list_counter, align 8, !tbaa !19
  %5 = tail call i8* @malloc(i64 56) #5
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %create_descriptor.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str4, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %8) #5
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %2
  %10 = bitcast i8* %5 to %struct.list_descriptor*
  %11 = getelementptr inbounds i8* %5, i64 16
  %12 = bitcast i8* %11 to i64*
  store i64 %3, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %5, i64 40
  %14 = bitcast i8* %13 to i64*
  store i64 3, i64* %14, align 8, !tbaa !20
  %15 = getelementptr inbounds i8* %5, i64 24
  %16 = getelementptr inbounds i8* %5, i64 48
  %17 = bitcast i8* %16 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %5, i8 0, i64 16, i32 8, i1 false) #5
  tail call void @llvm.memset.p0i8.i64(i8* %15, i8 0, i64 16, i32 8, i1 false) #5
  %18 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %19 = load %struct.list_descriptor** %18, align 8, !tbaa !5
  store %struct.list_descriptor* %19, %struct.list_descriptor** %17, align 8, !tbaa !7
  store %struct.list_descriptor* %10, %struct.list_descriptor** %18, align 8, !tbaa !5
  br label %20

; <label>:20                                      ; preds = %0, %create_descriptor.exit
  %.0 = phi i64 [ %3, %create_descriptor.exit ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_allocate_string(%struct.list_table* %table) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %20, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @list_counter, align 8, !tbaa !19
  %4 = add i64 %3, 1
  store i64 %4, i64* @list_counter, align 8, !tbaa !19
  %5 = tail call i8* @malloc(i64 56) #5
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %create_descriptor.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str4, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %8) #5
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %2
  %10 = bitcast i8* %5 to %struct.list_descriptor*
  %11 = getelementptr inbounds i8* %5, i64 16
  %12 = bitcast i8* %11 to i64*
  store i64 %3, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %5, i64 40
  %14 = bitcast i8* %13 to i64*
  store i64 4, i64* %14, align 8, !tbaa !20
  %15 = getelementptr inbounds i8* %5, i64 24
  %16 = getelementptr inbounds i8* %5, i64 48
  %17 = bitcast i8* %16 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %5, i8 0, i64 16, i32 8, i1 false) #5
  tail call void @llvm.memset.p0i8.i64(i8* %15, i8 0, i64 16, i32 8, i1 false) #5
  %18 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %19 = load %struct.list_descriptor** %18, align 8, !tbaa !5
  store %struct.list_descriptor* %19, %struct.list_descriptor** %17, align 8, !tbaa !7
  store %struct.list_descriptor* %10, %struct.list_descriptor** %18, align 8, !tbaa !5
  br label %20

; <label>:20                                      ; preds = %0, %create_descriptor.exit
  %.0 = phi i64 [ %3, %create_descriptor.exit ], [ 0, %0 ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i32 @list_front_int(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %get_list_element.exit

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 0, i64 0) #5
  tail call void @exit(i32 1) #6
  unreachable

get_list_element.exit:                            ; preds = %11
  %18 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %18, align 8
  %19 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 0
  %20 = load i8** %19, align 8, !tbaa !13
  %21 = bitcast i8* %20 to i32*
  %22 = load i32* %21, align 4, !tbaa !21
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i32 [ %22, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @list_front_float(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %get_list_element.exit

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 0, i64 0) #5
  tail call void @exit(i32 1) #6
  unreachable

get_list_element.exit:                            ; preds = %11
  %18 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %18, align 8
  %19 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 0
  %20 = load i8** %19, align 8, !tbaa !13
  %21 = bitcast i8* %20 to float*
  %22 = load float* %21, align 4, !tbaa !23
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi float [ %22, %get_list_element.exit ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @list_front_bool(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %get_list_element.exit

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 0, i64 0) #5
  tail call void @exit(i32 1) #6
  unreachable

get_list_element.exit:                            ; preds = %11
  %18 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %18, align 8
  %19 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 0
  %20 = load i8** %19, align 8, !tbaa !13
  %21 = load i8* %20, align 1, !tbaa !25, !range !27
  %22 = icmp ne i8 %21, 0
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i1 [ %22, %get_list_element.exit ], [ false, %0 ], [ false, %2 ], [ false, %find_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @list_front_char(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %get_list_element.exit

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 0, i64 0) #5
  tail call void @exit(i32 1) #6
  unreachable

get_list_element.exit:                            ; preds = %11
  %18 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %18, align 8
  %19 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 0
  %20 = load i8** %19, align 8, !tbaa !13
  %21 = load i8* %20, align 1, !tbaa !28
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i8 [ %21, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_front_string(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %get_list_element.exit

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 0, i64 0) #5
  tail call void @exit(i32 1) #6
  unreachable

get_list_element.exit:                            ; preds = %11
  %18 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %18, align 8
  %19 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 0
  %20 = load i8** %19, align 8, !tbaa !13
  %21 = bitcast i8* %20 to i64*
  %22 = load i64* %21, align 8, !tbaa !19
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i64 [ %22, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i32 @list_back_int(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %13, i64 -1)
  %14 = extractvalue { i64, i1 } %uadd, 0
  %15 = extractvalue { i64, i1 } %uadd, 1
  br i1 %15, label %19, label %16

; <label>:16                                      ; preds = %11
  %17 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %18 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %17, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %14, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:19                                      ; preds = %11
  %20 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %20, align 8
  %21 = icmp eq i64 %14, 0
  br i1 %21, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %19
  %xtraiter = and i64 %14, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %14, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %22 = add i64 0, 1
  %23 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %23, align 8
  %24 = icmp eq i64 %22, %14
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %22, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %25 = add i64 %cnt.03.i9.unr, 1
  %26 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %26, align 8
  %27 = icmp eq i64 %25, %14
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %25, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %28 = add i64 %cnt.03.i9.unr21, 1
  %29 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %29, align 8
  %30 = icmp eq i64 %28, %14
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %28, %.lr.ph.i2.unr19 ]
  %31 = icmp ult i64 %14, 4
  br i1 %31, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %19
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %19 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %32 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %33 = load i8** %32, align 8, !tbaa !13
  %34 = bitcast i8* %33 to i32*
  %35 = load i32* %34, align 4, !tbaa !21
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %42, %.lr.ph.i2 ]
  %36 = add i64 %cnt.03.i9, 1
  %37 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %37, align 8
  %38 = add i64 %36, 1
  %39 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %39, align 8
  %40 = add i64 %38, 1
  %41 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %41, align 8
  %42 = add i64 %40, 1
  %43 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %43, align 8
  %44 = icmp eq i64 %42, %14
  br i1 %44, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i32 [ %35, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @list_back_float(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %13, i64 -1)
  %14 = extractvalue { i64, i1 } %uadd, 0
  %15 = extractvalue { i64, i1 } %uadd, 1
  br i1 %15, label %19, label %16

; <label>:16                                      ; preds = %11
  %17 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %18 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %17, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %14, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:19                                      ; preds = %11
  %20 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %20, align 8
  %21 = icmp eq i64 %14, 0
  br i1 %21, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %19
  %xtraiter = and i64 %14, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %14, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %22 = add i64 0, 1
  %23 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %23, align 8
  %24 = icmp eq i64 %22, %14
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %22, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %25 = add i64 %cnt.03.i9.unr, 1
  %26 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %26, align 8
  %27 = icmp eq i64 %25, %14
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %25, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %28 = add i64 %cnt.03.i9.unr21, 1
  %29 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %29, align 8
  %30 = icmp eq i64 %28, %14
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %28, %.lr.ph.i2.unr19 ]
  %31 = icmp ult i64 %14, 4
  br i1 %31, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %19
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %19 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %32 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %33 = load i8** %32, align 8, !tbaa !13
  %34 = bitcast i8* %33 to float*
  %35 = load float* %34, align 4, !tbaa !23
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %42, %.lr.ph.i2 ]
  %36 = add i64 %cnt.03.i9, 1
  %37 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %37, align 8
  %38 = add i64 %36, 1
  %39 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %39, align 8
  %40 = add i64 %38, 1
  %41 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %41, align 8
  %42 = add i64 %40, 1
  %43 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %43, align 8
  %44 = icmp eq i64 %42, %14
  br i1 %44, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi float [ %35, %get_list_element.exit ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @list_back_bool(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %13, i64 -1)
  %14 = extractvalue { i64, i1 } %uadd, 0
  %15 = extractvalue { i64, i1 } %uadd, 1
  br i1 %15, label %19, label %16

; <label>:16                                      ; preds = %11
  %17 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %18 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %17, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %14, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:19                                      ; preds = %11
  %20 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %20, align 8
  %21 = icmp eq i64 %14, 0
  br i1 %21, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %19
  %xtraiter = and i64 %14, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %14, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %22 = add i64 0, 1
  %23 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %23, align 8
  %24 = icmp eq i64 %22, %14
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %22, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %25 = add i64 %cnt.03.i9.unr, 1
  %26 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %26, align 8
  %27 = icmp eq i64 %25, %14
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %25, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %28 = add i64 %cnt.03.i9.unr21, 1
  %29 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %29, align 8
  %30 = icmp eq i64 %28, %14
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %28, %.lr.ph.i2.unr19 ]
  %31 = icmp ult i64 %14, 4
  br i1 %31, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %19
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %19 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %32 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %33 = load i8** %32, align 8, !tbaa !13
  %34 = load i8* %33, align 1, !tbaa !25, !range !27
  %35 = icmp ne i8 %34, 0
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %42, %.lr.ph.i2 ]
  %36 = add i64 %cnt.03.i9, 1
  %37 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %37, align 8
  %38 = add i64 %36, 1
  %39 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %39, align 8
  %40 = add i64 %38, 1
  %41 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %41, align 8
  %42 = add i64 %40, 1
  %43 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %43, align 8
  %44 = icmp eq i64 %42, %14
  br i1 %44, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i1 [ %35, %get_list_element.exit ], [ false, %0 ], [ false, %2 ], [ false, %find_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @list_back_char(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %13, i64 -1)
  %14 = extractvalue { i64, i1 } %uadd, 0
  %15 = extractvalue { i64, i1 } %uadd, 1
  br i1 %15, label %19, label %16

; <label>:16                                      ; preds = %11
  %17 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %18 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %17, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %14, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:19                                      ; preds = %11
  %20 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %20, align 8
  %21 = icmp eq i64 %14, 0
  br i1 %21, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %19
  %xtraiter = and i64 %14, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %14, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %22 = add i64 0, 1
  %23 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %23, align 8
  %24 = icmp eq i64 %22, %14
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %22, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %25 = add i64 %cnt.03.i9.unr, 1
  %26 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %26, align 8
  %27 = icmp eq i64 %25, %14
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %25, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %28 = add i64 %cnt.03.i9.unr21, 1
  %29 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %29, align 8
  %30 = icmp eq i64 %28, %14
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %28, %.lr.ph.i2.unr19 ]
  %31 = icmp ult i64 %14, 4
  br i1 %31, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %19
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %19 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %32 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %33 = load i8** %32, align 8, !tbaa !13
  %34 = load i8* %33, align 1, !tbaa !28
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %41, %.lr.ph.i2 ]
  %35 = add i64 %cnt.03.i9, 1
  %36 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %36, align 8
  %37 = add i64 %35, 1
  %38 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %38, align 8
  %39 = add i64 %37, 1
  %40 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %40, align 8
  %41 = add i64 %39, 1
  %42 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %42, align 8
  %43 = icmp eq i64 %41, %14
  br i1 %43, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i8 [ %34, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_back_string(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %13, i64 -1)
  %14 = extractvalue { i64, i1 } %uadd, 0
  %15 = extractvalue { i64, i1 } %uadd, 1
  br i1 %15, label %19, label %16

; <label>:16                                      ; preds = %11
  %17 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %18 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %17, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %14, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:19                                      ; preds = %11
  %20 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %20, align 8
  %21 = icmp eq i64 %14, 0
  br i1 %21, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %19
  %xtraiter = and i64 %14, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %14, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %22 = add i64 0, 1
  %23 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %23, align 8
  %24 = icmp eq i64 %22, %14
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %22, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %25 = add i64 %cnt.03.i9.unr, 1
  %26 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %26, align 8
  %27 = icmp eq i64 %25, %14
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %25, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %28 = add i64 %cnt.03.i9.unr21, 1
  %29 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %29, align 8
  %30 = icmp eq i64 %28, %14
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %28, %.lr.ph.i2.unr19 ]
  %31 = icmp ult i64 %14, 4
  br i1 %31, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %19
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %19 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %32 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %33 = load i8** %32, align 8, !tbaa !13
  %34 = bitcast i8* %33 to i64*
  %35 = load i64* %34, align 8, !tbaa !19
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %42, %.lr.ph.i2 ]
  %36 = add i64 %cnt.03.i9, 1
  %37 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %37, align 8
  %38 = add i64 %36, 1
  %39 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %39, align 8
  %40 = add i64 %38, 1
  %41 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %41, align 8
  %42 = add i64 %40, 1
  %43 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %43, align 8
  %44 = icmp eq i64 %42, %14
  br i1 %44, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i64 [ %35, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i32 @list_pop_front_int(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0)
  %13 = bitcast i8* %12 to i32*
  %14 = load i32* %13, align 4, !tbaa !21
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i32 [ %14, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define internal fastcc i8* @remove_list_element(%struct.list_descriptor* nocapture %desc, i64 %pos) #0 {
  %1 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 3
  %2 = load i64* %1, align 8, !tbaa !15
  %3 = icmp ugt i64 %2, %pos
  br i1 %3, label %7, label %4

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %2) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 0
  %9 = load %struct.node_t** %8, align 8, !tbaa !10
  %10 = icmp eq %struct.node_t* %9, null
  br i1 %10, label %.loopexit, label %.lr.ph.preheader

.lr.ph.preheader:                                 ; preds = %7
  br label %.lr.ph

; <label>:11                                      ; preds = %.lr.ph
  %12 = add i64 %cnt.05, 1
  %13 = icmp eq %struct.node_t* %16, null
  br i1 %13, label %.loopexit.loopexit, label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph.preheader, %11
  %cnt.05 = phi i64 [ %12, %11 ], [ 0, %.lr.ph.preheader ]
  %current.04 = phi %struct.node_t* [ %16, %11 ], [ %9, %.lr.ph.preheader ]
  %14 = icmp eq i64 %cnt.05, %pos
  %15 = getelementptr inbounds %struct.node_t* %current.04, i64 0, i32 1
  %16 = load %struct.node_t** %15, align 8, !tbaa !11
  br i1 %14, label %17, label %11

; <label>:17                                      ; preds = %.lr.ph
  %.lcssa18 = phi %struct.node_t* [ %16, %.lr.ph ]
  %.lcssa = phi %struct.node_t** [ %15, %.lr.ph ]
  %current.04.lcssa = phi %struct.node_t* [ %current.04, %.lr.ph ]
  %18 = icmp eq %struct.node_t* %.lcssa18, null
  %19 = getelementptr inbounds %struct.node_t* %current.04.lcssa, i64 0, i32 2
  %20 = load %struct.node_t** %19, align 8, !tbaa !16
  %21 = icmp eq %struct.node_t* %20, null
  br i1 %18, label %31, label %22

; <label>:22                                      ; preds = %17
  br i1 %21, label %27, label %23

; <label>:23                                      ; preds = %22
  %24 = getelementptr inbounds %struct.node_t* %20, i64 0, i32 1
  store %struct.node_t* %.lcssa18, %struct.node_t** %24, align 8, !tbaa !11
  %25 = load %struct.node_t** %.lcssa, align 8, !tbaa !11
  %26 = getelementptr inbounds %struct.node_t* %25, i64 0, i32 2
  store %struct.node_t* %20, %struct.node_t** %26, align 8, !tbaa !16
  br label %37

; <label>:27                                      ; preds = %22
  store %struct.node_t* %.lcssa18, %struct.node_t** %8, align 8, !tbaa !10
  %28 = getelementptr inbounds %struct.node_t* %current.04.lcssa, i64 0, i32 2
  %29 = load %struct.node_t** %28, align 8, !tbaa !16
  %30 = getelementptr inbounds %struct.node_t* %.lcssa18, i64 0, i32 2
  store %struct.node_t* %29, %struct.node_t** %30, align 8, !tbaa !16
  br label %37

; <label>:31                                      ; preds = %17
  br i1 %21, label %35, label %32

; <label>:32                                      ; preds = %31
  %33 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  store %struct.node_t* %20, %struct.node_t** %33, align 8, !tbaa !17
  %34 = getelementptr inbounds %struct.node_t* %20, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %34, align 8, !tbaa !11
  br label %37

; <label>:35                                      ; preds = %31
  %36 = bitcast %struct.list_descriptor* %desc to i8*
  call void @llvm.memset.p0i8.i64(i8* %36, i8 0, i64 16, i32 8, i1 false)
  br label %37

; <label>:37                                      ; preds = %27, %35, %32, %23
  %38 = getelementptr inbounds %struct.node_t* %current.04.lcssa, i64 0, i32 0
  %39 = load i8** %38, align 8, !tbaa !13
  %40 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 5
  %41 = load i64* %40, align 8, !tbaa !20
  %42 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %41
  %43 = load i64* %42, align 8, !tbaa !19
  %44 = tail call i8* @malloc(i64 %43) #5
  %45 = icmp eq i8* %44, null
  br i1 %45, label %46, label %free_node.exit

; <label>:46                                      ; preds = %37
  %47 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %48 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str3, i64 0, i64 0), i64 41, i64 1, %struct.__sFILE* %47) #5
  tail call void @exit(i32 1) #6
  unreachable

free_node.exit:                                   ; preds = %37
  %49 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %44, i1 false) #5
  %50 = tail call i8* @__memcpy_chk(i8* %44, i8* %39, i64 %43, i64 %49) #5
  %51 = load i8** %38, align 8, !tbaa !13
  tail call void @free(i8* %51) #5
  %52 = bitcast %struct.node_t* %current.04.lcssa to i8*
  tail call void @free(i8* %52) #5
  %53 = load i64* %1, align 8, !tbaa !15
  %54 = add i64 %53, -1
  store i64 %54, i64* %1, align 8, !tbaa !15
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %11
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %7, %free_node.exit
  %.0 = phi i8* [ %44, %free_node.exit ], [ null, %7 ], [ null, %.loopexit.loopexit ]
  ret i8* %.0
}

; Function Attrs: nounwind ssp uwtable
define float @list_pop_front_float(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0)
  %13 = bitcast i8* %12 to float*
  %14 = load float* %13, align 4, !tbaa !23
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi float [ %14, %11 ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @list_pop_front_bool(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0)
  %13 = load i8* %12, align 1, !tbaa !25, !range !27
  %14 = icmp ne i8 %13, 0
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i1 [ %14, %11 ], [ false, %0 ], [ false, %2 ], [ false, %find_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @list_pop_front_char(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0)
  %13 = load i8* %12, align 1, !tbaa !28
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i8 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_pop_front_string(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0)
  %13 = bitcast i8* %12 to i64*
  %14 = load i64* %13, align 8, !tbaa !19
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i64 [ %14, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i32 @list_pop_back_int(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = add i64 %13, -1
  %15 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14)
  %16 = bitcast i8* %15 to i32*
  %17 = load i32* %16, align 4, !tbaa !21
  tail call void @free(i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i32 [ %17, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @list_pop_back_float(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = add i64 %13, -1
  %15 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14)
  %16 = bitcast i8* %15 to float*
  %17 = load float* %16, align 4, !tbaa !23
  tail call void @free(i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi float [ %17, %11 ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @list_pop_back_bool(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = add i64 %13, -1
  %15 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14)
  %16 = load i8* %15, align 1, !tbaa !25, !range !27
  %17 = icmp ne i8 %16, 0
  tail call void @free(i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i1 [ %17, %11 ], [ false, %0 ], [ false, %2 ], [ false, %find_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @list_pop_back_char(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = add i64 %13, -1
  %15 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14)
  %16 = load i8* %15, align 1, !tbaa !28
  tail call void @free(i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i8 [ %16, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_pop_back_string(%struct.list_table* readonly %table, i64 %lid) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = add i64 %13, -1
  %15 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14)
  %16 = bitcast i8* %15 to i64*
  %17 = load i64* %16, align 8, !tbaa !19
  tail call void @free(i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i64 [ %17, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_front_int(%struct.list_table* readonly %table, i64 %lid, i32 %value) #0 {
  %1 = alloca i32, align 4
  store i32 %value, i32* %1, align 4, !tbaa !21
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = bitcast i32* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0, i8* %13)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define internal fastcc void @insert_list_element(%struct.list_descriptor* nocapture %desc, i64 %pos, i8* %elem) #0 {
  %1 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 3
  %2 = load i64* %1, align 8, !tbaa !15
  %3 = icmp ult i64 %2, %pos
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %2) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:7                                       ; preds = %0
  %8 = icmp eq i64 %2, %pos
  br i1 %8, label %9, label %26

; <label>:9                                       ; preds = %7
  %10 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 5
  %11 = load i64* %10, align 8, !tbaa !20
  %12 = tail call fastcc %struct.node_t* @create_node(i8* %elem, i64 %11)
  %13 = load i64* %1, align 8, !tbaa !15
  %14 = icmp eq i64 %13, 0
  br i1 %14, label %15, label %17

; <label>:15                                      ; preds = %9
  %16 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 0
  store %struct.node_t* %12, %struct.node_t** %16, align 8, !tbaa !10
  %.phi.trans.insert = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  %.pre = load %struct.node_t** %.phi.trans.insert, align 8, !tbaa !17
  br label %21

; <label>:17                                      ; preds = %9
  %18 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  %19 = load %struct.node_t** %18, align 8, !tbaa !17
  %20 = getelementptr inbounds %struct.node_t* %19, i64 0, i32 1
  store %struct.node_t* %12, %struct.node_t** %20, align 8, !tbaa !11
  br label %21

; <label>:21                                      ; preds = %17, %15
  %22 = phi %struct.node_t* [ %19, %17 ], [ %.pre, %15 ]
  %23 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  %24 = getelementptr inbounds %struct.node_t* %12, i64 0, i32 2
  store %struct.node_t* %22, %struct.node_t** %24, align 8, !tbaa !16
  store %struct.node_t* %12, %struct.node_t** %23, align 8, !tbaa !17
  %25 = add i64 %13, 1
  store i64 %25, i64* %1, align 8, !tbaa !15
  br label %.loopexit

; <label>:26                                      ; preds = %7
  %27 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 0
  %current.03 = load %struct.node_t** %27, align 8
  %28 = icmp eq %struct.node_t* %current.03, null
  br i1 %28, label %.loopexit, label %.lr.ph.preheader

.lr.ph.preheader:                                 ; preds = %26
  br label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph.preheader, %46
  %current.05 = phi %struct.node_t* [ %current.0, %46 ], [ %current.03, %.lr.ph.preheader ]
  %cnt.04 = phi i64 [ %47, %46 ], [ 0, %.lr.ph.preheader ]
  %29 = icmp eq i64 %cnt.04, %pos
  br i1 %29, label %30, label %46

; <label>:30                                      ; preds = %.lr.ph
  %current.05.lcssa = phi %struct.node_t* [ %current.05, %.lr.ph ]
  %31 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 5
  %32 = load i64* %31, align 8, !tbaa !20
  %33 = tail call fastcc %struct.node_t* @create_node(i8* %elem, i64 %32)
  %34 = getelementptr inbounds %struct.node_t* %current.05.lcssa, i64 0, i32 2
  %35 = load %struct.node_t** %34, align 8, !tbaa !16
  %36 = icmp eq %struct.node_t* %35, null
  %37 = getelementptr inbounds %struct.node_t* %33, i64 0, i32 2
  store %struct.node_t* %35, %struct.node_t** %37, align 8, !tbaa !16
  %38 = getelementptr inbounds %struct.node_t* %33, i64 0, i32 1
  store %struct.node_t* %current.05.lcssa, %struct.node_t** %38, align 8, !tbaa !11
  br i1 %36, label %42, label %39

; <label>:39                                      ; preds = %30
  %40 = load %struct.node_t** %34, align 8, !tbaa !16
  %41 = getelementptr inbounds %struct.node_t* %40, i64 0, i32 1
  store %struct.node_t* %33, %struct.node_t** %41, align 8, !tbaa !11
  br label %43

; <label>:42                                      ; preds = %30
  store %struct.node_t* %33, %struct.node_t** %27, align 8, !tbaa !10
  br label %43

; <label>:43                                      ; preds = %42, %39
  store %struct.node_t* %33, %struct.node_t** %34, align 8, !tbaa !16
  %44 = load i64* %1, align 8, !tbaa !15
  %45 = add i64 %44, 1
  store i64 %45, i64* %1, align 8, !tbaa !15
  br label %.loopexit

; <label>:46                                      ; preds = %.lr.ph
  %47 = add i64 %cnt.04, 1
  %48 = getelementptr inbounds %struct.node_t* %current.05, i64 0, i32 1
  %current.0 = load %struct.node_t** %48, align 8
  %49 = icmp eq %struct.node_t* %current.0, null
  br i1 %49, label %.loopexit.loopexit, label %.lr.ph

.loopexit.loopexit:                               ; preds = %46
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %26, %21, %43
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_front_float(%struct.list_table* readonly %table, i64 %lid, float %value) #0 {
  %1 = alloca float, align 4
  store float %value, float* %1, align 4, !tbaa !23
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = bitcast float* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0, i8* %13)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_front_bool(%struct.list_table* readonly %table, i64 %lid, i1 zeroext %value) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %value to i8
  store i8 %2, i8* %1, align 1, !tbaa !25
  %3 = icmp eq %struct.list_table* %table, null
  br i1 %3, label %find_descriptor.exit.thread, label %4

; <label>:4                                       ; preds = %0
  %5 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %5, align 8
  %6 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %6, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %4
  br label %.lr.ph.i

; <label>:7                                       ; preds = %.lr.ph.i
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %8, align 8
  %9 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %9, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %7
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %7 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %10 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %11 = load i64* %10, align 8, !tbaa !14
  %12 = icmp eq i64 %11, %lid
  br i1 %12, label %13, label %7

; <label>:13                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0, i8* %1)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %7
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %4, %0, %13
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_front_char(%struct.list_table* readonly %table, i64 %lid, i8 signext %value) #0 {
  %1 = alloca i8, align 1
  store i8 %value, i8* %1, align 1, !tbaa !28
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0, i8* %1)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_front_string(%struct.list_table* readonly %table, i64 %lid, i64 %value) #0 {
  %1 = alloca i64, align 8
  store i64 %value, i64* %1, align 8, !tbaa !19
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = bitcast i64* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 0, i8* %13)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_back_int(%struct.list_table* readonly %table, i64 %lid, i32 %value) #0 {
  %1 = alloca i32, align 4
  store i32 %value, i32* %1, align 4, !tbaa !21
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %14 = load i64* %13, align 8, !tbaa !15
  %15 = bitcast i32* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14, i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_back_float(%struct.list_table* readonly %table, i64 %lid, float %value) #0 {
  %1 = alloca float, align 4
  store float %value, float* %1, align 4, !tbaa !23
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %14 = load i64* %13, align 8, !tbaa !15
  %15 = bitcast float* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14, i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_back_bool(%struct.list_table* readonly %table, i64 %lid, i1 zeroext %value) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %value to i8
  store i8 %2, i8* %1, align 1, !tbaa !25
  %3 = icmp eq %struct.list_table* %table, null
  br i1 %3, label %find_descriptor.exit.thread, label %4

; <label>:4                                       ; preds = %0
  %5 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %5, align 8
  %6 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %6, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %4
  br label %.lr.ph.i

; <label>:7                                       ; preds = %.lr.ph.i
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %8, align 8
  %9 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %9, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %7
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %7 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %10 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %11 = load i64* %10, align 8, !tbaa !14
  %12 = icmp eq i64 %11, %lid
  br i1 %12, label %13, label %7

; <label>:13                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %14 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %15 = load i64* %14, align 8, !tbaa !15
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %15, i8* %1)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %7
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %4, %0, %13
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_back_char(%struct.list_table* readonly %table, i64 %lid, i8 signext %value) #0 {
  %1 = alloca i8, align 1
  store i8 %value, i8* %1, align 1, !tbaa !28
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %14 = load i64* %13, align 8, !tbaa !15
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14, i8* %1)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_push_back_string(%struct.list_table* readonly %table, i64 %lid, i64 %value) #0 {
  %1 = alloca i64, align 8
  store i64 %value, i64* %1, align 8, !tbaa !19
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %14 = load i64* %13, align 8, !tbaa !15
  %15 = bitcast i64* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %14, i8* %15)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i32 @list_get_element_int(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp ugt i64 %13, %pos
  br i1 %14, label %18, label %15

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:18                                      ; preds = %11
  %19 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %19, align 8
  %20 = icmp eq i64 %pos, 0
  br i1 %20, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %18
  %xtraiter = and i64 %pos, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %pos, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %21 = add i64 0, 1
  %22 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %22, align 8
  %23 = icmp eq i64 %21, %pos
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %21, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %24 = add i64 %cnt.03.i9.unr, 1
  %25 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %25, align 8
  %26 = icmp eq i64 %24, %pos
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %24, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %27 = add i64 %cnt.03.i9.unr21, 1
  %28 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %28, align 8
  %29 = icmp eq i64 %27, %pos
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %27, %.lr.ph.i2.unr19 ]
  %30 = icmp ult i64 %pos, 4
  br i1 %30, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %18
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %18 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %31 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %32 = load i8** %31, align 8, !tbaa !13
  %33 = bitcast i8* %32 to i32*
  %34 = load i32* %33, align 4, !tbaa !21
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %41, %.lr.ph.i2 ]
  %35 = add i64 %cnt.03.i9, 1
  %36 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %36, align 8
  %37 = add i64 %35, 1
  %38 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %38, align 8
  %39 = add i64 %37, 1
  %40 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %40, align 8
  %41 = add i64 %39, 1
  %42 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %42, align 8
  %43 = icmp eq i64 %41, %pos
  br i1 %43, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i32 [ %34, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @list_get_element_float(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp ugt i64 %13, %pos
  br i1 %14, label %18, label %15

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:18                                      ; preds = %11
  %19 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %19, align 8
  %20 = icmp eq i64 %pos, 0
  br i1 %20, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %18
  %xtraiter = and i64 %pos, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %pos, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %21 = add i64 0, 1
  %22 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %22, align 8
  %23 = icmp eq i64 %21, %pos
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %21, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %24 = add i64 %cnt.03.i9.unr, 1
  %25 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %25, align 8
  %26 = icmp eq i64 %24, %pos
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %24, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %27 = add i64 %cnt.03.i9.unr21, 1
  %28 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %28, align 8
  %29 = icmp eq i64 %27, %pos
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %27, %.lr.ph.i2.unr19 ]
  %30 = icmp ult i64 %pos, 4
  br i1 %30, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %18
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %18 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %31 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %32 = load i8** %31, align 8, !tbaa !13
  %33 = bitcast i8* %32 to float*
  %34 = load float* %33, align 4, !tbaa !23
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %41, %.lr.ph.i2 ]
  %35 = add i64 %cnt.03.i9, 1
  %36 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %36, align 8
  %37 = add i64 %35, 1
  %38 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %38, align 8
  %39 = add i64 %37, 1
  %40 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %40, align 8
  %41 = add i64 %39, 1
  %42 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %42, align 8
  %43 = icmp eq i64 %41, %pos
  br i1 %43, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi float [ %34, %get_list_element.exit ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @list_get_element_bool(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp ugt i64 %13, %pos
  br i1 %14, label %18, label %15

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:18                                      ; preds = %11
  %19 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %19, align 8
  %20 = icmp eq i64 %pos, 0
  br i1 %20, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %18
  %xtraiter = and i64 %pos, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %pos, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %21 = add i64 0, 1
  %22 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %22, align 8
  %23 = icmp eq i64 %21, %pos
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %21, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %24 = add i64 %cnt.03.i9.unr, 1
  %25 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %25, align 8
  %26 = icmp eq i64 %24, %pos
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %24, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %27 = add i64 %cnt.03.i9.unr21, 1
  %28 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %28, align 8
  %29 = icmp eq i64 %27, %pos
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %27, %.lr.ph.i2.unr19 ]
  %30 = icmp ult i64 %pos, 4
  br i1 %30, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %18
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %18 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %31 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %32 = load i8** %31, align 8, !tbaa !13
  %33 = load i8* %32, align 1, !tbaa !25, !range !27
  %34 = icmp ne i8 %33, 0
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %41, %.lr.ph.i2 ]
  %35 = add i64 %cnt.03.i9, 1
  %36 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %36, align 8
  %37 = add i64 %35, 1
  %38 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %38, align 8
  %39 = add i64 %37, 1
  %40 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %40, align 8
  %41 = add i64 %39, 1
  %42 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %42, align 8
  %43 = icmp eq i64 %41, %pos
  br i1 %43, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i1 [ %34, %get_list_element.exit ], [ false, %0 ], [ false, %2 ], [ false, %find_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @list_get_element_char(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp ugt i64 %13, %pos
  br i1 %14, label %18, label %15

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:18                                      ; preds = %11
  %19 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %19, align 8
  %20 = icmp eq i64 %pos, 0
  br i1 %20, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %18
  %xtraiter = and i64 %pos, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %pos, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %21 = add i64 0, 1
  %22 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %22, align 8
  %23 = icmp eq i64 %21, %pos
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %21, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %24 = add i64 %cnt.03.i9.unr, 1
  %25 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %25, align 8
  %26 = icmp eq i64 %24, %pos
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %24, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %27 = add i64 %cnt.03.i9.unr21, 1
  %28 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %28, align 8
  %29 = icmp eq i64 %27, %pos
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %27, %.lr.ph.i2.unr19 ]
  %30 = icmp ult i64 %pos, 4
  br i1 %30, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %18
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %18 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %31 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %32 = load i8** %31, align 8, !tbaa !13
  %33 = load i8* %32, align 1, !tbaa !28
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %40, %.lr.ph.i2 ]
  %34 = add i64 %cnt.03.i9, 1
  %35 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %35, align 8
  %36 = add i64 %34, 1
  %37 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %37, align 8
  %38 = add i64 %36, 1
  %39 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %39, align 8
  %40 = add i64 %38, 1
  %41 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %41, align 8
  %42 = icmp eq i64 %40, %pos
  br i1 %42, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i8 [ %33, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_get_element_string(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %14 = icmp ugt i64 %13, %pos
  br i1 %14, label %18, label %15

; <label>:15                                      ; preds = %11
  %16 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %17 = tail call i32 (%struct.__sFILE*, i8*, ...)* @fprintf(%struct.__sFILE* %16, i8* getelementptr inbounds ([69 x i8]* @.str1, i64 0, i64 0), i64 %pos, i64 %13) #5
  tail call void @exit(i32 1) #6
  unreachable

; <label>:18                                      ; preds = %11
  %19 = getelementptr inbounds %struct.list_descriptor* %current.02.i.lcssa, i64 0, i32 0
  %current.04.i8 = load %struct.node_t** %19, align 8
  %20 = icmp eq i64 %pos, 0
  br i1 %20, label %get_list_element.exit, label %.lr.ph.i2.preheader

.lr.ph.i2.preheader:                              ; preds = %18
  %xtraiter = and i64 %pos, 3
  %lcmp.mod = icmp ne i64 %xtraiter, 0
  %lcmp.overflow = icmp eq i64 %pos, 0
  %lcmp.or = or i1 %lcmp.overflow, %lcmp.mod
  br i1 %lcmp.or, label %unr.cmp23, label %.lr.ph.i2.preheader.split

unr.cmp23:                                        ; preds = %.lr.ph.i2.preheader
  %un.tmp24 = icmp eq i64 %xtraiter, 1
  br i1 %un.tmp24, label %.lr.ph.i2.unr19, label %unr.cmp

unr.cmp:                                          ; preds = %unr.cmp23
  %un.tmp = icmp eq i64 %xtraiter, 2
  br i1 %un.tmp, label %.lr.ph.i2.unr17, label %.lr.ph.i2.unr

.lr.ph.i2.unr:                                    ; preds = %unr.cmp
  %21 = add i64 0, 1
  %22 = getelementptr inbounds %struct.node_t* %current.04.i8, i64 0, i32 1
  %current.04.i.unr = load %struct.node_t** %22, align 8
  %23 = icmp eq i64 %21, %pos
  br label %.lr.ph.i2.unr17

.lr.ph.i2.unr17:                                  ; preds = %unr.cmp, %.lr.ph.i2.unr
  %current.04.i10.unr = phi %struct.node_t* [ %current.04.i.unr, %.lr.ph.i2.unr ], [ %current.04.i8, %unr.cmp ]
  %cnt.03.i9.unr = phi i64 [ %21, %.lr.ph.i2.unr ], [ 0, %unr.cmp ]
  %24 = add i64 %cnt.03.i9.unr, 1
  %25 = getelementptr inbounds %struct.node_t* %current.04.i10.unr, i64 0, i32 1
  %current.04.i.unr18 = load %struct.node_t** %25, align 8
  %26 = icmp eq i64 %24, %pos
  br label %.lr.ph.i2.unr19

.lr.ph.i2.unr19:                                  ; preds = %unr.cmp23, %.lr.ph.i2.unr17
  %current.04.i10.unr20 = phi %struct.node_t* [ %current.04.i.unr18, %.lr.ph.i2.unr17 ], [ %current.04.i8, %unr.cmp23 ]
  %cnt.03.i9.unr21 = phi i64 [ %24, %.lr.ph.i2.unr17 ], [ 0, %unr.cmp23 ]
  %27 = add i64 %cnt.03.i9.unr21, 1
  %28 = getelementptr inbounds %struct.node_t* %current.04.i10.unr20, i64 0, i32 1
  %current.04.i.unr22 = load %struct.node_t** %28, align 8
  %29 = icmp eq i64 %27, %pos
  br label %.lr.ph.i2.preheader.split

.lr.ph.i2.preheader.split:                        ; preds = %.lr.ph.i2.unr19, %.lr.ph.i2.preheader
  %current.04.i.lcssa15.unr = phi %struct.node_t* [ null, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %current.04.i10.unr25 = phi %struct.node_t* [ %current.04.i8, %.lr.ph.i2.preheader ], [ %current.04.i.unr22, %.lr.ph.i2.unr19 ]
  %cnt.03.i9.unr26 = phi i64 [ 0, %.lr.ph.i2.preheader ], [ %27, %.lr.ph.i2.unr19 ]
  %30 = icmp ult i64 %pos, 4
  br i1 %30, label %get_list_element.exit.loopexit, label %.lr.ph.i2.preheader.split.split

.lr.ph.i2.preheader.split.split:                  ; preds = %.lr.ph.i2.preheader.split
  br label %.lr.ph.i2

get_list_element.exit.loopexit.unr-lcssa:         ; preds = %.lr.ph.i2
  %current.04.i.lcssa15.ph = phi %struct.node_t* [ %current.04.i.3, %.lr.ph.i2 ]
  br label %get_list_element.exit.loopexit

get_list_element.exit.loopexit:                   ; preds = %.lr.ph.i2.preheader.split, %get_list_element.exit.loopexit.unr-lcssa
  %current.04.i.lcssa15 = phi %struct.node_t* [ %current.04.i.lcssa15.unr, %.lr.ph.i2.preheader.split ], [ %current.04.i.lcssa15.ph, %get_list_element.exit.loopexit.unr-lcssa ]
  br label %get_list_element.exit

get_list_element.exit:                            ; preds = %get_list_element.exit.loopexit, %18
  %current.04.i.lcssa = phi %struct.node_t* [ %current.04.i8, %18 ], [ %current.04.i.lcssa15, %get_list_element.exit.loopexit ]
  %31 = getelementptr inbounds %struct.node_t* %current.04.i.lcssa, i64 0, i32 0
  %32 = load i8** %31, align 8, !tbaa !13
  %33 = bitcast i8* %32 to i64*
  %34 = load i64* %33, align 8, !tbaa !19
  br label %find_descriptor.exit.thread

.lr.ph.i2:                                        ; preds = %.lr.ph.i2, %.lr.ph.i2.preheader.split.split
  %current.04.i10 = phi %struct.node_t* [ %current.04.i10.unr25, %.lr.ph.i2.preheader.split.split ], [ %current.04.i.3, %.lr.ph.i2 ]
  %cnt.03.i9 = phi i64 [ %cnt.03.i9.unr26, %.lr.ph.i2.preheader.split.split ], [ %41, %.lr.ph.i2 ]
  %35 = add i64 %cnt.03.i9, 1
  %36 = getelementptr inbounds %struct.node_t* %current.04.i10, i64 0, i32 1
  %current.04.i = load %struct.node_t** %36, align 8
  %37 = add i64 %35, 1
  %38 = getelementptr inbounds %struct.node_t* %current.04.i, i64 0, i32 1
  %current.04.i.1 = load %struct.node_t** %38, align 8
  %39 = add i64 %37, 1
  %40 = getelementptr inbounds %struct.node_t* %current.04.i.1, i64 0, i32 1
  %current.04.i.2 = load %struct.node_t** %40, align 8
  %41 = add i64 %39, 1
  %42 = getelementptr inbounds %struct.node_t* %current.04.i.2, i64 0, i32 1
  %current.04.i.3 = load %struct.node_t** %42, align 8
  %43 = icmp eq i64 %41, %pos
  br i1 %43, label %get_list_element.exit.loopexit.unr-lcssa, label %.lr.ph.i2

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %get_list_element.exit
  %.0 = phi i64 [ %34, %get_list_element.exit ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define void @list_insert_element_int(%struct.list_table* readonly %table, i64 %lid, i64 %pos, i32 %value) #0 {
  %1 = alloca i32, align 4
  store i32 %value, i32* %1, align 4, !tbaa !21
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = bitcast i32* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos, i8* %13)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_insert_element_float(%struct.list_table* readonly %table, i64 %lid, i64 %pos, float %value) #0 {
  %1 = alloca float, align 4
  store float %value, float* %1, align 4, !tbaa !23
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = bitcast float* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos, i8* %13)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_insert_element_bool(%struct.list_table* readonly %table, i64 %lid, i64 %pos, i1 zeroext %value) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %value to i8
  store i8 %2, i8* %1, align 1, !tbaa !25
  %3 = icmp eq %struct.list_table* %table, null
  br i1 %3, label %find_descriptor.exit.thread, label %4

; <label>:4                                       ; preds = %0
  %5 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %5, align 8
  %6 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %6, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %4
  br label %.lr.ph.i

; <label>:7                                       ; preds = %.lr.ph.i
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %8, align 8
  %9 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %9, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %7
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %7 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %10 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %11 = load i64* %10, align 8, !tbaa !14
  %12 = icmp eq i64 %11, %lid
  br i1 %12, label %13, label %7

; <label>:13                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos, i8* %1)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %7
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %4, %0, %13
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_insert_element_char(%struct.list_table* readonly %table, i64 %lid, i64 %pos, i8 signext %value) #0 {
  %1 = alloca i8, align 1
  store i8 %value, i8* %1, align 1, !tbaa !28
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos, i8* %1)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_insert_element_string(%struct.list_table* readonly %table, i64 %lid, i64 %pos, i64 %value) #0 {
  %1 = alloca i64, align 8
  store i64 %value, i64* %1, align 8, !tbaa !19
  %2 = icmp eq %struct.list_table* %table, null
  br i1 %2, label %find_descriptor.exit.thread, label %3

; <label>:3                                       ; preds = %0
  %4 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %4, align 8
  %5 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %5, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %3
  br label %.lr.ph.i

; <label>:6                                       ; preds = %.lr.ph.i
  %7 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %7, align 8
  %8 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %8, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %6
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %6 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %9 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %10 = load i64* %9, align 8, !tbaa !14
  %11 = icmp eq i64 %10, %lid
  br i1 %11, label %12, label %6

; <label>:12                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %13 = bitcast i64* %1 to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos, i8* %13)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %6
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %3, %0, %12
  ret void
}

; Function Attrs: nounwind ssp uwtable
define i32 @list_remove_element_int(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos)
  %13 = bitcast i8* %12 to i32*
  %14 = load i32* %13, align 4, !tbaa !21
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i32 [ %14, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind ssp uwtable
define float @list_remove_element_float(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos)
  %13 = bitcast i8* %12 to float*
  %14 = load float* %13, align 4, !tbaa !23
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi float [ %14, %11 ], [ 0.000000e+00, %0 ], [ 0.000000e+00, %2 ], [ 0.000000e+00, %find_descriptor.exit.thread.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind ssp uwtable
define zeroext i1 @list_remove_element_bool(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos)
  %13 = load i8* %12, align 1, !tbaa !25, !range !27
  %14 = icmp ne i8 %13, 0
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i1 [ %14, %11 ], [ false, %0 ], [ false, %2 ], [ false, %find_descriptor.exit.thread.loopexit ]
  ret i1 %.0
}

; Function Attrs: nounwind ssp uwtable
define signext i8 @list_remove_element_char(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos)
  %13 = load i8* %12, align 1, !tbaa !28
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i8 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i8 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_remove_element_string(%struct.list_table* readonly %table, i64 %lid, i64 %pos) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit.thread, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i, null
  br i1 %4, label %find_descriptor.exit.thread, label %.lr.ph.i.preheader

.lr.ph.i.preheader:                               ; preds = %2
  br label %.lr.ph.i

; <label>:5                                       ; preds = %.lr.ph.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %7, label %find_descriptor.exit.thread.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %.lr.ph.i.preheader, %5
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %5 ], [ %current.01.i, %.lr.ph.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %lid
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i
  %current.02.i.lcssa = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ]
  %12 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.02.i.lcssa, i64 %pos)
  %13 = bitcast i8* %12 to i64*
  %14 = load i64* %13, align 8, !tbaa !19
  tail call void @free(i8* %12)
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread.loopexit:             ; preds = %5
  br label %find_descriptor.exit.thread

find_descriptor.exit.thread:                      ; preds = %find_descriptor.exit.thread.loopexit, %2, %0, %11
  %.0 = phi i64 [ %14, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %find_descriptor.exit.thread.loopexit ]
  ret i64 %.0
}

; Function Attrs: nounwind ssp uwtable
define i64 @list_make_sequence(%struct.list_table* %table, i64 %a, i64 %b) #0 {
  %i = alloca i64, align 8
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %find_descriptor.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = load i64* @list_counter, align 8, !tbaa !19
  %4 = add i64 %3, 1
  store i64 %4, i64* @list_counter, align 8, !tbaa !19
  %5 = tail call i8* @malloc(i64 56) #5
  %6 = icmp eq i8* %5, null
  br i1 %6, label %7, label %list_allocate_int.exit

; <label>:7                                       ; preds = %2
  %8 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str4, i64 0, i64 0), i64 49, i64 1, %struct.__sFILE* %8) #5
  tail call void @exit(i32 1) #6
  unreachable

list_allocate_int.exit:                           ; preds = %2
  %10 = bitcast i8* %5 to %struct.list_descriptor*
  %11 = getelementptr inbounds i8* %5, i64 16
  %12 = bitcast i8* %11 to i64*
  store i64 %3, i64* %12, align 8, !tbaa !14
  %13 = getelementptr inbounds i8* %5, i64 24
  %14 = getelementptr inbounds i8* %5, i64 48
  %15 = bitcast i8* %14 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %5, i8 0, i64 16, i32 8, i1 false) #5
  %16 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  tail call void @llvm.memset.p0i8.i64(i8* %13, i8 0, i64 24, i32 8, i1 false) #5
  %17 = load %struct.list_descriptor** %16, align 8, !tbaa !5
  store %struct.list_descriptor* %17, %struct.list_descriptor** %15, align 8, !tbaa !7
  store %struct.list_descriptor* %10, %struct.list_descriptor** %16, align 8, !tbaa !5
  br label %.lr.ph.i

; <label>:18                                      ; preds = %.lr.ph.i
  %19 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %19, align 8
  %20 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %20, label %find_descriptor.exit.loopexit, label %.lr.ph.i

.lr.ph.i:                                         ; preds = %list_allocate_int.exit, %18
  %current.02.i = phi %struct.list_descriptor* [ %current.0.i, %18 ], [ %10, %list_allocate_int.exit ]
  %21 = getelementptr inbounds %struct.list_descriptor* %current.02.i, i64 0, i32 2
  %22 = load i64* %21, align 8, !tbaa !14
  %23 = icmp eq i64 %22, %3
  br i1 %23, label %find_descriptor.exit.loopexit, label %18

find_descriptor.exit.loopexit:                    ; preds = %.lr.ph.i, %18
  %.0.i1.ph = phi %struct.list_descriptor* [ %current.02.i, %.lr.ph.i ], [ null, %18 ]
  br label %find_descriptor.exit

find_descriptor.exit:                             ; preds = %find_descriptor.exit.loopexit, %0
  %.0.i3 = phi i64 [ 0, %0 ], [ %3, %find_descriptor.exit.loopexit ]
  %.0.i1 = phi %struct.list_descriptor* [ null, %0 ], [ %.0.i1.ph, %find_descriptor.exit.loopexit ]
  store i64 %a, i64* %i, align 8, !tbaa !19
  %24 = icmp ugt i64 %a, %b
  br i1 %24, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %find_descriptor.exit
  %25 = getelementptr inbounds %struct.list_descriptor* %.0.i1, i64 0, i32 3
  %26 = bitcast i64* %i to i8*
  br label %27

; <label>:27                                      ; preds = %.lr.ph, %27
  %28 = load i64* %25, align 8, !tbaa !15
  call fastcc void @insert_list_element(%struct.list_descriptor* %.0.i1, i64 %28, i8* %26)
  %29 = load i64* %i, align 8, !tbaa !19
  %30 = add i64 %29, 1
  store i64 %30, i64* %i, align 8, !tbaa !19
  %31 = icmp ugt i64 %30, %b
  br i1 %31, label %._crit_edge.loopexit, label %27

._crit_edge.loopexit:                             ; preds = %27
  br label %._crit_edge

._crit_edge:                                      ; preds = %._crit_edge.loopexit, %find_descriptor.exit
  ret i64 %.0.i3
}

; Function Attrs: nounwind readonly ssp uwtable
define zeroext i1 @list_empty_int(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_empty.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i.i, null
  br i1 %4, label %list_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %2
  br label %.lr.ph.i.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %7, label %list_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %5
  %current.02.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %5 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %phitmp.i = icmp eq i64 %13, 0
  br label %list_empty.exit

list_empty.exit.loopexit:                         ; preds = %5
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %list_empty.exit.loopexit, %0, %2, %11
  %.0.i.i = phi i1 [ %phitmp.i, %11 ], [ true, %0 ], [ true, %2 ], [ true, %list_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind readonly ssp uwtable
define zeroext i1 @list_empty_bool(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_empty.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i.i, null
  br i1 %4, label %list_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %2
  br label %.lr.ph.i.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %7, label %list_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %5
  %current.02.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %5 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %phitmp.i = icmp eq i64 %13, 0
  br label %list_empty.exit

list_empty.exit.loopexit:                         ; preds = %5
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %list_empty.exit.loopexit, %0, %2, %11
  %.0.i.i = phi i1 [ %phitmp.i, %11 ], [ true, %0 ], [ true, %2 ], [ true, %list_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind readonly ssp uwtable
define zeroext i1 @list_empty_float(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_empty.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i.i, null
  br i1 %4, label %list_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %2
  br label %.lr.ph.i.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %7, label %list_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %5
  %current.02.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %5 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %phitmp.i = icmp eq i64 %13, 0
  br label %list_empty.exit

list_empty.exit.loopexit:                         ; preds = %5
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %list_empty.exit.loopexit, %0, %2, %11
  %.0.i.i = phi i1 [ %phitmp.i, %11 ], [ true, %0 ], [ true, %2 ], [ true, %list_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind readonly ssp uwtable
define zeroext i1 @list_empty_string(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_empty.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i.i, null
  br i1 %4, label %list_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %2
  br label %.lr.ph.i.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %7, label %list_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %5
  %current.02.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %5 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %phitmp.i = icmp eq i64 %13, 0
  br label %list_empty.exit

list_empty.exit.loopexit:                         ; preds = %5
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %list_empty.exit.loopexit, %0, %2, %11
  %.0.i.i = phi i1 [ %phitmp.i, %11 ], [ true, %0 ], [ true, %2 ], [ true, %list_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind readonly ssp uwtable
define zeroext i1 @list_empty_char(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_empty.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i.i, null
  br i1 %4, label %list_empty.exit, label %.lr.ph.i.i.i.preheader

.lr.ph.i.i.i.preheader:                           ; preds = %2
  br label %.lr.ph.i.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %7, label %list_empty.exit.loopexit, label %.lr.ph.i.i.i

.lr.ph.i.i.i:                                     ; preds = %.lr.ph.i.i.i.preheader, %5
  %current.02.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %5 ], [ %current.01.i.i.i, %.lr.ph.i.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i.i
  %current.02.i.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i.i, %.lr.ph.i.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  %phitmp.i = icmp eq i64 %13, 0
  br label %list_empty.exit

list_empty.exit.loopexit:                         ; preds = %5
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %list_empty.exit.loopexit, %0, %2, %11
  %.0.i.i = phi i1 [ %phitmp.i, %11 ], [ true, %0 ], [ true, %2 ], [ true, %list_empty.exit.loopexit ]
  ret i1 %.0.i.i
}

; Function Attrs: nounwind ssp uwtable
define void @list_clear_int(%struct.list_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_clear.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 0
  %13 = load %struct.node_t** %12, align 8, !tbaa !10
  %14 = icmp eq %struct.node_t* %13, null
  br i1 %14, label %list_clear.exit, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.node_t* %13, i64 0, i32 2
  %17 = load %struct.node_t** %16, align 8, !tbaa !16
  %18 = icmp eq %struct.node_t* %17, null
  br i1 %18, label %free_node.exit.i.i.preheader, label %.preheader.i.i

.preheader.i.i:                                   ; preds = %15
  %19 = getelementptr inbounds %struct.node_t* %17, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %19, align 8, !tbaa !11
  br label %free_node.exit.i.i.preheader

free_node.exit.i.i.preheader:                     ; preds = %15, %.preheader.i.i
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %free_node.exit.i.i.preheader, %free_node.exit.i.i
  %.01.i.i = phi %struct.node_t* [ %21, %free_node.exit.i.i ], [ %13, %free_node.exit.i.i.preheader ]
  %20 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 1
  %21 = load %struct.node_t** %20, align 8, !tbaa !11
  %22 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 0
  %23 = load i8** %22, align 8, !tbaa !13
  tail call void @free(i8* %23) #5
  %24 = bitcast %struct.node_t* %.01.i.i to i8*
  tail call void @free(i8* %24) #5
  %25 = icmp eq %struct.node_t* %21, null
  br i1 %25, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %26 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store %struct.node_t* %17, %struct.node_t** %26, align 8, !tbaa !17
  store %struct.node_t* %17, %struct.node_t** %12, align 8, !tbaa !10
  %27 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  store i64 0, i64* %27, align 8, !tbaa !15
  br label %list_clear.exit

list_clear.exit.loopexit:                         ; preds = %5
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %list_clear.exit.loopexit, %0, %2, %11, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_clear_bool(%struct.list_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_clear.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 0
  %13 = load %struct.node_t** %12, align 8, !tbaa !10
  %14 = icmp eq %struct.node_t* %13, null
  br i1 %14, label %list_clear.exit, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.node_t* %13, i64 0, i32 2
  %17 = load %struct.node_t** %16, align 8, !tbaa !16
  %18 = icmp eq %struct.node_t* %17, null
  br i1 %18, label %free_node.exit.i.i.preheader, label %.preheader.i.i

.preheader.i.i:                                   ; preds = %15
  %19 = getelementptr inbounds %struct.node_t* %17, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %19, align 8, !tbaa !11
  br label %free_node.exit.i.i.preheader

free_node.exit.i.i.preheader:                     ; preds = %15, %.preheader.i.i
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %free_node.exit.i.i.preheader, %free_node.exit.i.i
  %.01.i.i = phi %struct.node_t* [ %21, %free_node.exit.i.i ], [ %13, %free_node.exit.i.i.preheader ]
  %20 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 1
  %21 = load %struct.node_t** %20, align 8, !tbaa !11
  %22 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 0
  %23 = load i8** %22, align 8, !tbaa !13
  tail call void @free(i8* %23) #5
  %24 = bitcast %struct.node_t* %.01.i.i to i8*
  tail call void @free(i8* %24) #5
  %25 = icmp eq %struct.node_t* %21, null
  br i1 %25, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %26 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store %struct.node_t* %17, %struct.node_t** %26, align 8, !tbaa !17
  store %struct.node_t* %17, %struct.node_t** %12, align 8, !tbaa !10
  %27 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  store i64 0, i64* %27, align 8, !tbaa !15
  br label %list_clear.exit

list_clear.exit.loopexit:                         ; preds = %5
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %list_clear.exit.loopexit, %0, %2, %11, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_clear_float(%struct.list_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_clear.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 0
  %13 = load %struct.node_t** %12, align 8, !tbaa !10
  %14 = icmp eq %struct.node_t* %13, null
  br i1 %14, label %list_clear.exit, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.node_t* %13, i64 0, i32 2
  %17 = load %struct.node_t** %16, align 8, !tbaa !16
  %18 = icmp eq %struct.node_t* %17, null
  br i1 %18, label %free_node.exit.i.i.preheader, label %.preheader.i.i

.preheader.i.i:                                   ; preds = %15
  %19 = getelementptr inbounds %struct.node_t* %17, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %19, align 8, !tbaa !11
  br label %free_node.exit.i.i.preheader

free_node.exit.i.i.preheader:                     ; preds = %15, %.preheader.i.i
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %free_node.exit.i.i.preheader, %free_node.exit.i.i
  %.01.i.i = phi %struct.node_t* [ %21, %free_node.exit.i.i ], [ %13, %free_node.exit.i.i.preheader ]
  %20 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 1
  %21 = load %struct.node_t** %20, align 8, !tbaa !11
  %22 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 0
  %23 = load i8** %22, align 8, !tbaa !13
  tail call void @free(i8* %23) #5
  %24 = bitcast %struct.node_t* %.01.i.i to i8*
  tail call void @free(i8* %24) #5
  %25 = icmp eq %struct.node_t* %21, null
  br i1 %25, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %26 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store %struct.node_t* %17, %struct.node_t** %26, align 8, !tbaa !17
  store %struct.node_t* %17, %struct.node_t** %12, align 8, !tbaa !10
  %27 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  store i64 0, i64* %27, align 8, !tbaa !15
  br label %list_clear.exit

list_clear.exit.loopexit:                         ; preds = %5
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %list_clear.exit.loopexit, %0, %2, %11, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_clear_string(%struct.list_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_clear.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 0
  %13 = load %struct.node_t** %12, align 8, !tbaa !10
  %14 = icmp eq %struct.node_t* %13, null
  br i1 %14, label %list_clear.exit, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.node_t* %13, i64 0, i32 2
  %17 = load %struct.node_t** %16, align 8, !tbaa !16
  %18 = icmp eq %struct.node_t* %17, null
  br i1 %18, label %free_node.exit.i.i.preheader, label %.preheader.i.i

.preheader.i.i:                                   ; preds = %15
  %19 = getelementptr inbounds %struct.node_t* %17, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %19, align 8, !tbaa !11
  br label %free_node.exit.i.i.preheader

free_node.exit.i.i.preheader:                     ; preds = %15, %.preheader.i.i
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %free_node.exit.i.i.preheader, %free_node.exit.i.i
  %.01.i.i = phi %struct.node_t* [ %21, %free_node.exit.i.i ], [ %13, %free_node.exit.i.i.preheader ]
  %20 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 1
  %21 = load %struct.node_t** %20, align 8, !tbaa !11
  %22 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 0
  %23 = load i8** %22, align 8, !tbaa !13
  tail call void @free(i8* %23) #5
  %24 = bitcast %struct.node_t* %.01.i.i to i8*
  tail call void @free(i8* %24) #5
  %25 = icmp eq %struct.node_t* %21, null
  br i1 %25, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %26 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store %struct.node_t* %17, %struct.node_t** %26, align 8, !tbaa !17
  store %struct.node_t* %17, %struct.node_t** %12, align 8, !tbaa !10
  %27 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  store i64 0, i64* %27, align 8, !tbaa !15
  br label %list_clear.exit

list_clear.exit.loopexit:                         ; preds = %5
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %list_clear.exit.loopexit, %0, %2, %11, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @list_clear_char(%struct.list_table* readonly %table, i64 %id) #0 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_clear.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_clear.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_clear.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 0
  %13 = load %struct.node_t** %12, align 8, !tbaa !10
  %14 = icmp eq %struct.node_t* %13, null
  br i1 %14, label %list_clear.exit, label %15

; <label>:15                                      ; preds = %11
  %16 = getelementptr inbounds %struct.node_t* %13, i64 0, i32 2
  %17 = load %struct.node_t** %16, align 8, !tbaa !16
  %18 = icmp eq %struct.node_t* %17, null
  br i1 %18, label %free_node.exit.i.i.preheader, label %.preheader.i.i

.preheader.i.i:                                   ; preds = %15
  %19 = getelementptr inbounds %struct.node_t* %17, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %19, align 8, !tbaa !11
  br label %free_node.exit.i.i.preheader

free_node.exit.i.i.preheader:                     ; preds = %15, %.preheader.i.i
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %free_node.exit.i.i.preheader, %free_node.exit.i.i
  %.01.i.i = phi %struct.node_t* [ %21, %free_node.exit.i.i ], [ %13, %free_node.exit.i.i.preheader ]
  %20 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 1
  %21 = load %struct.node_t** %20, align 8, !tbaa !11
  %22 = getelementptr inbounds %struct.node_t* %.01.i.i, i64 0, i32 0
  %23 = load i8** %22, align 8, !tbaa !13
  tail call void @free(i8* %23) #5
  %24 = bitcast %struct.node_t* %.01.i.i to i8*
  tail call void @free(i8* %24) #5
  %25 = icmp eq %struct.node_t* %21, null
  br i1 %25, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %26 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 1
  store %struct.node_t* %17, %struct.node_t** %26, align 8, !tbaa !17
  store %struct.node_t* %17, %struct.node_t** %12, align 8, !tbaa !10
  %27 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  store i64 0, i64* %27, align 8, !tbaa !15
  br label %list_clear.exit

list_clear.exit.loopexit:                         ; preds = %5
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %list_clear.exit.loopexit, %0, %2, %11, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind readonly ssp uwtable
define i64 @list_size_int(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_size.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  br label %list_size.exit

list_size.exit.loopexit:                          ; preds = %5
  br label %list_size.exit

list_size.exit:                                   ; preds = %list_size.exit.loopexit, %0, %2, %11
  %.0.i = phi i64 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %list_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind readonly ssp uwtable
define i64 @list_size_bool(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_size.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  br label %list_size.exit

list_size.exit.loopexit:                          ; preds = %5
  br label %list_size.exit

list_size.exit:                                   ; preds = %list_size.exit.loopexit, %0, %2, %11
  %.0.i = phi i64 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %list_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind readonly ssp uwtable
define i64 @list_size_float(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_size.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  br label %list_size.exit

list_size.exit.loopexit:                          ; preds = %5
  br label %list_size.exit

list_size.exit:                                   ; preds = %list_size.exit.loopexit, %0, %2, %11
  %.0.i = phi i64 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %list_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind readonly ssp uwtable
define i64 @list_size_string(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_size.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  br label %list_size.exit

list_size.exit.loopexit:                          ; preds = %5
  br label %list_size.exit

list_size.exit:                                   ; preds = %list_size.exit.loopexit, %0, %2, %11
  %.0.i = phi i64 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %list_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind readonly ssp uwtable
define i64 @list_size_char(%struct.list_table* readonly %table, i64 %id) #3 {
  %1 = icmp eq %struct.list_table* %table, null
  br i1 %1, label %list_size.exit, label %2

; <label>:2                                       ; preds = %0
  %3 = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.01.i.i = load %struct.list_descriptor** %3, align 8
  %4 = icmp eq %struct.list_descriptor* %current.01.i.i, null
  br i1 %4, label %list_size.exit, label %.lr.ph.i.i.preheader

.lr.ph.i.i.preheader:                             ; preds = %2
  br label %.lr.ph.i.i

; <label>:5                                       ; preds = %.lr.ph.i.i
  %6 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %6, align 8
  %7 = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %7, label %list_size.exit.loopexit, label %.lr.ph.i.i

.lr.ph.i.i:                                       ; preds = %.lr.ph.i.i.preheader, %5
  %current.02.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %5 ], [ %current.01.i.i, %.lr.ph.i.i.preheader ]
  %8 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i, i64 0, i32 2
  %9 = load i64* %8, align 8, !tbaa !14
  %10 = icmp eq i64 %9, %id
  br i1 %10, label %11, label %5

; <label>:11                                      ; preds = %.lr.ph.i.i
  %current.02.i.i.lcssa = phi %struct.list_descriptor* [ %current.02.i.i, %.lr.ph.i.i ]
  %12 = getelementptr inbounds %struct.list_descriptor* %current.02.i.i.lcssa, i64 0, i32 3
  %13 = load i64* %12, align 8, !tbaa !15
  br label %list_size.exit

list_size.exit.loopexit:                          ; preds = %5
  br label %list_size.exit

list_size.exit:                                   ; preds = %list_size.exit.loopexit, %0, %2, %11
  %.0.i = phi i64 [ %13, %11 ], [ 0, %0 ], [ 0, %2 ], [ 0, %list_size.exit.loopexit ]
  ret i64 %.0.i
}

; Function Attrs: nounwind ssp uwtable
define internal fastcc noalias %struct.node_t* @create_node(i8* %value, i64 %type) #0 {
  %1 = tail call i8* @malloc(i64 24) #5
  %2 = icmp eq i8* %1, null
  br i1 %2, label %3, label %6

; <label>:3                                       ; preds = %0
  %4 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([44 x i8]* @.str2, i64 0, i64 0), i64 43, i64 1, %struct.__sFILE* %4)
  tail call void @exit(i32 1) #6
  unreachable

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds i8* %1, i64 8
  %8 = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %type
  call void @llvm.memset.p0i8.i64(i8* %7, i8 0, i64 16, i32 8, i1 false)
  %9 = load i64* %8, align 8, !tbaa !19
  %10 = tail call i8* @malloc(i64 %9) #5
  %11 = icmp eq i8* %10, null
  br i1 %11, label %12, label %cpy_value.exit

; <label>:12                                      ; preds = %6
  %13 = load %struct.__sFILE** @__stderrp, align 8, !tbaa !1
  %14 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str3, i64 0, i64 0), i64 41, i64 1, %struct.__sFILE* %13) #5
  tail call void @exit(i32 1) #6
  unreachable

cpy_value.exit:                                   ; preds = %6
  %15 = bitcast i8* %1 to %struct.node_t*
  %16 = tail call i64 @llvm.objectsize.i64.p0i8(i8* %10, i1 false) #5
  %17 = tail call i8* @__memcpy_chk(i8* %10, i8* %value, i64 %9, i64 %16) #5
  %18 = bitcast i8* %1 to i8**
  store i8* %10, i8** %18, align 8, !tbaa !13
  ret %struct.node_t* %15
}

; Function Attrs: nounwind
declare i8* @__memcpy_chk(i8*, i8*, i64, i64) #1

; Function Attrs: nounwind readnone
declare i64 @llvm.objectsize.i64.p0i8(i8*, i1) #4

; Function Attrs: nounwind
declare i64 @fwrite(i8* nocapture, i64, i64, %struct.__sFILE* nocapture) #5

; Function Attrs: nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #5

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.uadd.with.overflow.i64(i64, i64) #4

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind readonly ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind readnone }
attributes #5 = { nounwind }
attributes #6 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.1.0 (clang-602.0.49) (based on LLVM 3.6.0svn)"}
!1 = metadata !{metadata !2, metadata !2, i64 0}
!2 = metadata !{metadata !"any pointer", metadata !3, i64 0}
!3 = metadata !{metadata !"omnipotent char", metadata !4, i64 0}
!4 = metadata !{metadata !"Simple C/C++ TBAA"}
!5 = metadata !{metadata !6, metadata !2, i64 0}
!6 = metadata !{metadata !"list_table", metadata !2, i64 0}
!7 = metadata !{metadata !8, metadata !2, i64 48}
!8 = metadata !{metadata !"list_descriptor", metadata !2, i64 0, metadata !2, i64 8, metadata !9, i64 16, metadata !9, i64 24, metadata !9, i64 32, metadata !9, i64 40, metadata !2, i64 48}
!9 = metadata !{metadata !"long", metadata !3, i64 0}
!10 = metadata !{metadata !8, metadata !2, i64 0}
!11 = metadata !{metadata !12, metadata !2, i64 8}
!12 = metadata !{metadata !"node_t", metadata !2, i64 0, metadata !2, i64 8, metadata !2, i64 16}
!13 = metadata !{metadata !12, metadata !2, i64 0}
!14 = metadata !{metadata !8, metadata !9, i64 16}
!15 = metadata !{metadata !8, metadata !9, i64 24}
!16 = metadata !{metadata !12, metadata !2, i64 16}
!17 = metadata !{metadata !8, metadata !2, i64 8}
!18 = metadata !{metadata !8, metadata !9, i64 32}
!19 = metadata !{metadata !9, metadata !9, i64 0}
!20 = metadata !{metadata !8, metadata !9, i64 40}
!21 = metadata !{metadata !22, metadata !22, i64 0}
!22 = metadata !{metadata !"int", metadata !3, i64 0}
!23 = metadata !{metadata !24, metadata !24, i64 0}
!24 = metadata !{metadata !"float", metadata !3, i64 0}
!25 = metadata !{metadata !26, metadata !26, i64 0}
!26 = metadata !{metadata !"_Bool", metadata !3, i64 0}
!27 = metadata !{i8 0, i8 2}
!28 = metadata !{metadata !3, metadata !3, i64 0}
