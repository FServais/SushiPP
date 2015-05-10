; ModuleID = 'list_runtime.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.list_table = type { %struct.list_descriptor* }
%struct.list_descriptor = type { %struct.node_t*, %struct.node_t*, i64, i64, i64, i64, %struct.list_descriptor* }
%struct.node_t = type { i8*, %struct.node_t*, %struct.node_t* }

@stderr = external global %struct._IO_FILE*
@.str = private unnamed_addr constant [50 x i8] c"Memory allocation failure in `create_list_table`\0A\00", align 1
@.str1 = private unnamed_addr constant [45 x i8] c"Out of range error in `insert_list_element`\0A\00", align 1
@.str2 = private unnamed_addr constant [44 x i8] c"Memory allocation failure in `create_node`\0A\00", align 1
@.str3 = private unnamed_addr constant [42 x i8] c"Memory allocation failure in `cpy_value`\0A\00", align 1
@bytes_per_type = internal unnamed_addr constant [5 x i64] [i64 4, i64 4, i64 1, i64 1, i64 8], align 16
@.str4 = private unnamed_addr constant [45 x i8] c"Out of range error in `remove_list_element`\0A\00", align 1
@.str5 = private unnamed_addr constant [42 x i8] c"Out of range error in `get_list_element`\0A\00", align 1
@list_counter = internal unnamed_addr global i64 1, align 8
@.str6 = private unnamed_addr constant [50 x i8] c"Memory allocation failure in `create_descriptor`\0A\00", align 1

; Function Attrs: nounwind uwtable
define noalias %struct.list_table* @create_list_table() #0 {
entry:
  %call = tail call noalias i8* @malloc(i64 8) #4
  %tobool = icmp eq i8* %call, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %0 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %1 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %0)
  tail call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %2 = bitcast i8* %call to %struct.list_table*
  %head = bitcast i8* %call to %struct.list_descriptor**
  store %struct.list_descriptor* null, %struct.list_descriptor** %head, align 8, !tbaa !0
  ret %struct.list_table* %2
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: noreturn nounwind
declare void @exit(i32) #2

; Function Attrs: nounwind uwtable
define void @delete_list_table(%struct.list_table* %table) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %0 = load %struct.list_descriptor** %head, align 8, !tbaa !0
  %tobool17 = icmp eq %struct.list_descriptor* %0, null
  br i1 %tobool17, label %while.end, label %while.body

while.body:                                       ; preds = %if.end, %free_descriptor.exit
  %current.08 = phi %struct.list_descriptor* [ %1, %free_descriptor.exit ], [ %0, %if.end ]
  %next2 = getelementptr inbounds %struct.list_descriptor* %current.08, i64 0, i32 6
  %1 = load %struct.list_descriptor** %next2, align 8, !tbaa !0
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.08, i64 0, i32 0
  %2 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool5.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool5.i, label %free_descriptor.exit, label %free_node.exit.i

free_node.exit.i:                                 ; preds = %while.body, %free_node.exit.i
  %current.06.i = phi %struct.node_t* [ %3, %free_node.exit.i ], [ %2, %while.body ]
  %next1.i = getelementptr inbounds %struct.node_t* %current.06.i, i64 0, i32 1
  %3 = load %struct.node_t** %next1.i, align 8, !tbaa !0
  %value.i.i = getelementptr inbounds %struct.node_t* %current.06.i, i64 0, i32 0
  %4 = load i8** %value.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %current.06.i to i8*
  tail call void @free(i8* %5) #4
  %tobool.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool.i, label %free_descriptor.exit, label %free_node.exit.i

free_descriptor.exit:                             ; preds = %free_node.exit.i, %while.body
  %6 = bitcast %struct.list_descriptor* %current.08 to i8*
  tail call void @free(i8* %6) #4
  %tobool1 = icmp eq %struct.list_descriptor* %1, null
  br i1 %tobool1, label %while.end, label %while.body

while.end:                                        ; preds = %free_descriptor.exit, %if.end
  %7 = bitcast %struct.list_table* %table to i8*
  tail call void @free(i8* %7) #4
  br label %return

return:                                           ; preds = %entry, %while.end
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #1

; Function Attrs: nounwind readonly uwtable
define i64 @list_size(%struct.list_table* %table, i64 %lid) #3 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i64 [ %1, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @list_empty(%struct.list_table* %table, i64 %lid) #3 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %lid
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %phitmp = icmp eq i64 %1, 0
  br label %list_size.exit

list_size.exit:                                   ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i1 [ %phitmp, %if.end3.i ], [ true, %entry ], [ true, %if.end.i ], [ true, %while.cond.i.i ]
  ret i1 %retval.0.i
}

; Function Attrs: nounwind uwtable
define void @list_clear(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_head = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %1 = load %struct.node_t** %list_head, align 8, !tbaa !0
  %tobool4 = icmp eq %struct.node_t* %1, null
  br i1 %tobool4, label %return, label %if.end6

if.end6:                                          ; preds = %if.end3
  %prev1.i = getelementptr inbounds %struct.node_t* %1, i64 0, i32 2
  %2 = load %struct.node_t** %prev1.i, align 8, !tbaa !0
  %tobool.i16 = icmp eq %struct.node_t* %2, null
  br i1 %tobool.i16, label %free_node.exit.i, label %while.cond.preheader.i

while.cond.preheader.i:                           ; preds = %if.end6
  %next.i17 = getelementptr inbounds %struct.node_t* %2, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next.i17, align 8, !tbaa !0
  br label %free_node.exit.i

free_node.exit.i:                                 ; preds = %while.cond.preheader.i, %if.end6, %free_node.exit.i
  %node.addr.011.i = phi %struct.node_t* [ %3, %free_node.exit.i ], [ %1, %if.end6 ], [ %1, %while.cond.preheader.i ]
  %next4.i = getelementptr inbounds %struct.node_t* %node.addr.011.i, i64 0, i32 1
  %3 = load %struct.node_t** %next4.i, align 8, !tbaa !0
  %value.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i, i64 0, i32 0
  %4 = load i8** %value.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %node.addr.011.i to i8*
  tail call void @free(i8* %5) #4
  %tobool2.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool2.i, label %free_node_recur.exit, label %free_node.exit.i

free_node_recur.exit:                             ; preds = %free_node.exit.i
  %list_tail = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 1
  store %struct.node_t* %2, %struct.node_t** %list_tail, align 8, !tbaa !0
  store %struct.node_t* %2, %struct.node_t** %list_head, align 8, !tbaa !0
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  store i64 0, i64* %list_size, align 8, !tbaa !3
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %if.end3, %entry, %free_node_recur.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_add_reference(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %ref_count = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 4
  %1 = load i64* %ref_count, align 8, !tbaa !3
  %inc = add i64 %1, 1
  store i64 %inc, i64* %ref_count, align 8, !tbaa !3
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_rm_reference(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %if.end6, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %if.end6, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %if.end6, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %ref_count = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 4
  %1 = load i64* %ref_count, align 8, !tbaa !3
  %dec = add i64 %1, -1
  store i64 %dec, i64* %ref_count, align 8, !tbaa !3
  %cmp.not = icmp eq i64 %dec, 0
  br i1 %cmp.not, label %if.end.i, label %if.end6

if.end.i:                                         ; preds = %if.end3
  %current.021.i = load %struct.list_descriptor** %head.i, align 8
  %tobool122.i = icmp eq %struct.list_descriptor* %current.021.i, null
  br i1 %tobool122.i, label %if.end6, label %while.body.i18

while.cond.i15:                                   ; preds = %while.body.i18
  %next10.i = getelementptr inbounds %struct.list_descriptor* %current.024.i, i64 0, i32 6
  %current.0.i14 = load %struct.list_descriptor** %next10.i, align 8
  %tobool1.i = icmp eq %struct.list_descriptor* %current.0.i14, null
  br i1 %tobool1.i, label %if.end6, label %while.body.i18

while.body.i18:                                   ; preds = %if.end.i, %while.cond.i15
  %current.024.i = phi %struct.list_descriptor* [ %current.0.i14, %while.cond.i15 ], [ %current.021.i, %if.end.i ]
  %prev.023.i = phi %struct.list_descriptor* [ %current.024.i, %while.cond.i15 ], [ null, %if.end.i ]
  %list_id.i16 = getelementptr inbounds %struct.list_descriptor* %current.024.i, i64 0, i32 2
  %2 = load i64* %list_id.i16, align 8, !tbaa !3
  %cmp.i17 = icmp eq i64 %2, %lid
  br i1 %cmp.i17, label %if.then2.i, label %while.cond.i15

if.then2.i:                                       ; preds = %while.body.i18
  %tobool3.i = icmp eq %struct.list_descriptor* %prev.023.i, null
  %next.i19 = getelementptr inbounds %struct.list_descriptor* %current.024.i, i64 0, i32 6
  %3 = load %struct.list_descriptor** %next.i19, align 8, !tbaa !0
  br i1 %tobool3.i, label %if.else.i, label %if.then4.i

if.then4.i:                                       ; preds = %if.then2.i
  %next5.i = getelementptr inbounds %struct.list_descriptor* %prev.023.i, i64 0, i32 6
  store %struct.list_descriptor* %3, %struct.list_descriptor** %next5.i, align 8, !tbaa !0
  br label %if.end8.i

if.else.i:                                        ; preds = %if.then2.i
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i, align 8, !tbaa !0
  br label %if.end8.i

if.end8.i:                                        ; preds = %if.else.i, %if.then4.i
  %list_head.i.i = getelementptr inbounds %struct.list_descriptor* %current.024.i, i64 0, i32 0
  %4 = load %struct.node_t** %list_head.i.i, align 8, !tbaa !0
  %tobool5.i.i = icmp eq %struct.node_t* %4, null
  br i1 %tobool5.i.i, label %free_descriptor.exit.i, label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %if.end8.i, %free_node.exit.i.i
  %current.06.i.i = phi %struct.node_t* [ %5, %free_node.exit.i.i ], [ %4, %if.end8.i ]
  %next1.i.i = getelementptr inbounds %struct.node_t* %current.06.i.i, i64 0, i32 1
  %5 = load %struct.node_t** %next1.i.i, align 8, !tbaa !0
  %value.i.i.i = getelementptr inbounds %struct.node_t* %current.06.i.i, i64 0, i32 0
  %6 = load i8** %value.i.i.i, align 8, !tbaa !0
  tail call void @free(i8* %6) #4
  %7 = bitcast %struct.node_t* %current.06.i.i to i8*
  tail call void @free(i8* %7) #4
  %tobool.i.i = icmp eq %struct.node_t* %5, null
  br i1 %tobool.i.i, label %free_descriptor.exit.i, label %free_node.exit.i.i

free_descriptor.exit.i:                           ; preds = %free_node.exit.i.i, %if.end8.i
  %8 = bitcast %struct.list_descriptor* %current.024.i to i8*
  tail call void @free(i8* %8) #4
  br label %if.end6

if.end6:                                          ; preds = %while.cond.i, %while.cond.i15, %if.end3, %if.end, %free_descriptor.exit.i, %if.end.i, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_deallocate(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %while.end, label %if.end

if.end:                                           ; preds = %entry
  %head = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.021 = load %struct.list_descriptor** %head, align 8
  %tobool122 = icmp eq %struct.list_descriptor* %current.021, null
  br i1 %tobool122, label %while.end, label %while.body

while.cond:                                       ; preds = %while.body
  %next10 = getelementptr inbounds %struct.list_descriptor* %current.024, i64 0, i32 6
  %current.0 = load %struct.list_descriptor** %next10, align 8
  %tobool1 = icmp eq %struct.list_descriptor* %current.0, null
  br i1 %tobool1, label %while.end, label %while.body

while.body:                                       ; preds = %if.end, %while.cond
  %current.024 = phi %struct.list_descriptor* [ %current.0, %while.cond ], [ %current.021, %if.end ]
  %prev.023 = phi %struct.list_descriptor* [ %current.024, %while.cond ], [ null, %if.end ]
  %list_id = getelementptr inbounds %struct.list_descriptor* %current.024, i64 0, i32 2
  %0 = load i64* %list_id, align 8, !tbaa !3
  %cmp = icmp eq i64 %0, %lid
  br i1 %cmp, label %if.then2, label %while.cond

if.then2:                                         ; preds = %while.body
  %tobool3 = icmp eq %struct.list_descriptor* %prev.023, null
  %next = getelementptr inbounds %struct.list_descriptor* %current.024, i64 0, i32 6
  %1 = load %struct.list_descriptor** %next, align 8, !tbaa !0
  br i1 %tobool3, label %if.else, label %if.then4

if.then4:                                         ; preds = %if.then2
  %next5 = getelementptr inbounds %struct.list_descriptor* %prev.023, i64 0, i32 6
  store %struct.list_descriptor* %1, %struct.list_descriptor** %next5, align 8, !tbaa !0
  br label %if.end8

if.else:                                          ; preds = %if.then2
  store %struct.list_descriptor* %1, %struct.list_descriptor** %head, align 8, !tbaa !0
  br label %if.end8

if.end8:                                          ; preds = %if.else, %if.then4
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.024, i64 0, i32 0
  %2 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool5.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool5.i, label %free_descriptor.exit, label %free_node.exit.i

free_node.exit.i:                                 ; preds = %if.end8, %free_node.exit.i
  %current.06.i = phi %struct.node_t* [ %3, %free_node.exit.i ], [ %2, %if.end8 ]
  %next1.i = getelementptr inbounds %struct.node_t* %current.06.i, i64 0, i32 1
  %3 = load %struct.node_t** %next1.i, align 8, !tbaa !0
  %value.i.i = getelementptr inbounds %struct.node_t* %current.06.i, i64 0, i32 0
  %4 = load i8** %value.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %current.06.i to i8*
  tail call void @free(i8* %5) #4
  %tobool.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool.i, label %free_descriptor.exit, label %free_node.exit.i

free_descriptor.exit:                             ; preds = %free_node.exit.i, %if.end8
  %6 = bitcast %struct.list_descriptor* %current.024 to i8*
  tail call void @free(i8* %6) #4
  br label %while.end

while.end:                                        ; preds = %if.end, %while.cond, %entry, %free_descriptor.exit
  ret void
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_int(%struct.list_table* %table) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @list_counter, align 8, !tbaa !3
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @list_counter, align 8, !tbaa !3
  %call.i = tail call noalias i8* @malloc(i64 56) #4
  %tobool.i = icmp eq i8* %call.i, null
  br i1 %tobool.i, label %if.then.i, label %create_descriptor.exit

if.then.i:                                        ; preds = %if.end
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str6, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %1) #4
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %if.end
  %3 = bitcast i8* %call.i to %struct.list_descriptor*
  %list_id.i = getelementptr inbounds i8* %call.i, i64 16
  %4 = bitcast i8* %list_id.i to i64*
  store i64 %0, i64* %4, align 8, !tbaa !3
  %list_size.i = getelementptr inbounds i8* %call.i, i64 24
  %next.i4 = getelementptr inbounds i8* %call.i, i64 48
  %5 = bitcast i8* %next.i4 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %call.i, i8 0, i64 16, i32 8, i1 false) #4
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  call void @llvm.memset.p0i8.i64(i8* %list_size.i, i8 0, i64 24, i32 8, i1 false)
  %6 = load %struct.list_descriptor** %head.i, align 8, !tbaa !0
  store %struct.list_descriptor* %6, %struct.list_descriptor** %5, align 8, !tbaa !0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %entry, %create_descriptor.exit
  %retval.0 = phi i64 [ %0, %create_descriptor.exit ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_float(%struct.list_table* %table) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @list_counter, align 8, !tbaa !3
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @list_counter, align 8, !tbaa !3
  %call.i = tail call noalias i8* @malloc(i64 56) #4
  %tobool.i = icmp eq i8* %call.i, null
  br i1 %tobool.i, label %if.then.i, label %create_descriptor.exit

if.then.i:                                        ; preds = %if.end
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str6, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %1) #4
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %if.end
  %3 = bitcast i8* %call.i to %struct.list_descriptor*
  %list_id.i = getelementptr inbounds i8* %call.i, i64 16
  %4 = bitcast i8* %list_id.i to i64*
  store i64 %0, i64* %4, align 8, !tbaa !3
  %type2.i = getelementptr inbounds i8* %call.i, i64 40
  %5 = bitcast i8* %type2.i to i64*
  store i64 1, i64* %5, align 8, !tbaa !3
  %list_size.i = getelementptr inbounds i8* %call.i, i64 24
  %next.i4 = getelementptr inbounds i8* %call.i, i64 48
  %6 = bitcast i8* %next.i4 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %call.i, i8 0, i64 16, i32 8, i1 false) #4
  tail call void @llvm.memset.p0i8.i64(i8* %list_size.i, i8 0, i64 16, i32 8, i1 false) #4
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %7 = load %struct.list_descriptor** %head.i, align 8, !tbaa !0
  store %struct.list_descriptor* %7, %struct.list_descriptor** %6, align 8, !tbaa !0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %entry, %create_descriptor.exit
  %retval.0 = phi i64 [ %0, %create_descriptor.exit ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_bool(%struct.list_table* %table) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @list_counter, align 8, !tbaa !3
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @list_counter, align 8, !tbaa !3
  %call.i = tail call noalias i8* @malloc(i64 56) #4
  %tobool.i = icmp eq i8* %call.i, null
  br i1 %tobool.i, label %if.then.i, label %create_descriptor.exit

if.then.i:                                        ; preds = %if.end
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str6, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %1) #4
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %if.end
  %3 = bitcast i8* %call.i to %struct.list_descriptor*
  %list_id.i = getelementptr inbounds i8* %call.i, i64 16
  %4 = bitcast i8* %list_id.i to i64*
  store i64 %0, i64* %4, align 8, !tbaa !3
  %type2.i = getelementptr inbounds i8* %call.i, i64 40
  %5 = bitcast i8* %type2.i to i64*
  store i64 2, i64* %5, align 8, !tbaa !3
  %list_size.i = getelementptr inbounds i8* %call.i, i64 24
  %next.i4 = getelementptr inbounds i8* %call.i, i64 48
  %6 = bitcast i8* %next.i4 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %call.i, i8 0, i64 16, i32 8, i1 false) #4
  tail call void @llvm.memset.p0i8.i64(i8* %list_size.i, i8 0, i64 16, i32 8, i1 false) #4
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %7 = load %struct.list_descriptor** %head.i, align 8, !tbaa !0
  store %struct.list_descriptor* %7, %struct.list_descriptor** %6, align 8, !tbaa !0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %entry, %create_descriptor.exit
  %retval.0 = phi i64 [ %0, %create_descriptor.exit ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_char(%struct.list_table* %table) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @list_counter, align 8, !tbaa !3
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @list_counter, align 8, !tbaa !3
  %call.i = tail call noalias i8* @malloc(i64 56) #4
  %tobool.i = icmp eq i8* %call.i, null
  br i1 %tobool.i, label %if.then.i, label %create_descriptor.exit

if.then.i:                                        ; preds = %if.end
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str6, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %1) #4
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %if.end
  %3 = bitcast i8* %call.i to %struct.list_descriptor*
  %list_id.i = getelementptr inbounds i8* %call.i, i64 16
  %4 = bitcast i8* %list_id.i to i64*
  store i64 %0, i64* %4, align 8, !tbaa !3
  %type2.i = getelementptr inbounds i8* %call.i, i64 40
  %5 = bitcast i8* %type2.i to i64*
  store i64 3, i64* %5, align 8, !tbaa !3
  %list_size.i = getelementptr inbounds i8* %call.i, i64 24
  %next.i4 = getelementptr inbounds i8* %call.i, i64 48
  %6 = bitcast i8* %next.i4 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %call.i, i8 0, i64 16, i32 8, i1 false) #4
  tail call void @llvm.memset.p0i8.i64(i8* %list_size.i, i8 0, i64 16, i32 8, i1 false) #4
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %7 = load %struct.list_descriptor** %head.i, align 8, !tbaa !0
  store %struct.list_descriptor* %7, %struct.list_descriptor** %6, align 8, !tbaa !0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %entry, %create_descriptor.exit
  %retval.0 = phi i64 [ %0, %create_descriptor.exit ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_string(%struct.list_table* %table) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @list_counter, align 8, !tbaa !3
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @list_counter, align 8, !tbaa !3
  %call.i = tail call noalias i8* @malloc(i64 56) #4
  %tobool.i = icmp eq i8* %call.i, null
  br i1 %tobool.i, label %if.then.i, label %create_descriptor.exit

if.then.i:                                        ; preds = %if.end
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str6, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %1) #4
  tail call void @exit(i32 1) #6
  unreachable

create_descriptor.exit:                           ; preds = %if.end
  %3 = bitcast i8* %call.i to %struct.list_descriptor*
  %list_id.i = getelementptr inbounds i8* %call.i, i64 16
  %4 = bitcast i8* %list_id.i to i64*
  store i64 %0, i64* %4, align 8, !tbaa !3
  %type2.i = getelementptr inbounds i8* %call.i, i64 40
  %5 = bitcast i8* %type2.i to i64*
  store i64 4, i64* %5, align 8, !tbaa !3
  %list_size.i = getelementptr inbounds i8* %call.i, i64 24
  %next.i4 = getelementptr inbounds i8* %call.i, i64 48
  %6 = bitcast i8* %next.i4 to %struct.list_descriptor**
  tail call void @llvm.memset.p0i8.i64(i8* %call.i, i8 0, i64 16, i32 8, i1 false) #4
  tail call void @llvm.memset.p0i8.i64(i8* %list_size.i, i8 0, i64 16, i32 8, i1 false) #4
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %7 = load %struct.list_descriptor** %head.i, align 8, !tbaa !0
  store %struct.list_descriptor* %7, %struct.list_descriptor** %6, align 8, !tbaa !0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %entry, %create_descriptor.exit
  %retval.0 = phi i64 [ %0, %create_descriptor.exit ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i32 @list_front_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp eq i64 %1, 0
  br i1 %cmp.i7, label %if.then.i, label %if.then2.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.then2.i:                                       ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i17, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = bitcast i8* %4 to i32*
  %6 = load i32* %5, align 4, !tbaa !4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i32 [ %6, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @list_front_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp eq i64 %1, 0
  br i1 %cmp.i7, label %if.then.i, label %if.then2.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.then2.i:                                       ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i17, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = bitcast i8* %4 to float*
  %6 = load float* %5, align 4, !tbaa !5
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi float [ %6, %if.then2.i ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_front_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i8 = icmp eq i64 %1, 0
  br i1 %cmp.i8, label %if.then.i, label %if.then2.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.then2.i:                                       ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i18 = load %struct.node_t** %list_head.i, align 8
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i18, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = load i8* %4, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %5, 0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i1 [ %tobool5, %if.then2.i ], [ false, %entry ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @list_front_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp eq i64 %1, 0
  br i1 %cmp.i7, label %if.then.i, label %if.then2.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.then2.i:                                       ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i17, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = load i8* %4, align 1, !tbaa !1
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i8 [ %5, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_front_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp eq i64 %1, 0
  br i1 %cmp.i7, label %if.then.i, label %if.then2.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.then2.i:                                       ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i17, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = bitcast i8* %4 to i64*
  %6 = load i64* %5, align 8, !tbaa !3
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i64 [ %6, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i32 @list_back_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %1, i64 -1)
  %2 = extractvalue { i64, i1 } %uadd, 0
  %cmp.i8 = extractvalue { i64, i1 } %uadd, 1
  br i1 %cmp.i8, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %3 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %3) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i18 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i19 = icmp eq i64 %2, 0
  br i1 %cmp1.i19, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i18, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %5 = load i8** %value.i, align 8, !tbaa !0
  %6 = bitcast i8* %5 to i32*
  %7 = load i32* %6, align 4, !tbaa !4
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i21 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i18, %if.end.i ]
  %cnt.010.i20 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i20, 1
  %next.i10 = getelementptr inbounds %struct.node_t* %current.011.i21, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i10, align 8
  %cmp1.i = icmp eq i64 %inc.i, %2
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i32 [ %7, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @list_back_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %1, i64 -1)
  %2 = extractvalue { i64, i1 } %uadd, 0
  %cmp.i8 = extractvalue { i64, i1 } %uadd, 1
  br i1 %cmp.i8, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %3 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %3) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i18 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i19 = icmp eq i64 %2, 0
  br i1 %cmp1.i19, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i18, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %5 = load i8** %value.i, align 8, !tbaa !0
  %6 = bitcast i8* %5 to float*
  %7 = load float* %6, align 4, !tbaa !5
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i21 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i18, %if.end.i ]
  %cnt.010.i20 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i20, 1
  %next.i10 = getelementptr inbounds %struct.node_t* %current.011.i21, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i10, align 8
  %cmp1.i = icmp eq i64 %inc.i, %2
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi float [ %7, %if.then2.i ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_back_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %1, i64 -1)
  %2 = extractvalue { i64, i1 } %uadd, 0
  %cmp.i9 = extractvalue { i64, i1 } %uadd, 1
  br i1 %cmp.i9, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %3 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %3) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i19 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i20 = icmp eq i64 %2, 0
  br i1 %cmp1.i20, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i19, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %5 = load i8** %value.i, align 8, !tbaa !0
  %6 = load i8* %5, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %6, 0
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i22 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i19, %if.end.i ]
  %cnt.010.i21 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i21, 1
  %next.i11 = getelementptr inbounds %struct.node_t* %current.011.i22, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i11, align 8
  %cmp1.i = icmp eq i64 %inc.i, %2
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i1 [ %tobool5, %if.then2.i ], [ false, %entry ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @list_back_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %1, i64 -1)
  %2 = extractvalue { i64, i1 } %uadd, 0
  %cmp.i8 = extractvalue { i64, i1 } %uadd, 1
  br i1 %cmp.i8, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %3 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %3) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i18 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i19 = icmp eq i64 %2, 0
  br i1 %cmp1.i19, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i18, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %5 = load i8** %value.i, align 8, !tbaa !0
  %6 = load i8* %5, align 1, !tbaa !1
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i21 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i18, %if.end.i ]
  %cnt.010.i20 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i20, 1
  %next.i10 = getelementptr inbounds %struct.node_t* %current.011.i21, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i10, align 8
  %cmp1.i = icmp eq i64 %inc.i, %2
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i8 [ %6, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_back_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %uadd = tail call { i64, i1 } @llvm.uadd.with.overflow.i64(i64 %1, i64 -1)
  %2 = extractvalue { i64, i1 } %uadd, 0
  %cmp.i8 = extractvalue { i64, i1 } %uadd, 1
  br i1 %cmp.i8, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %3 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %3) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i18 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i19 = icmp eq i64 %2, 0
  br i1 %cmp1.i19, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i18, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %5 = load i8** %value.i, align 8, !tbaa !0
  %6 = bitcast i8* %5 to i64*
  %7 = load i64* %6, align 8, !tbaa !3
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i21 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i18, %if.end.i ]
  %cnt.010.i20 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i20, 1
  %next.i10 = getelementptr inbounds %struct.node_t* %current.011.i21, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i10, align 8
  %cmp1.i = icmp eq i64 %inc.i, %2
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i64 [ %7, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i32 @list_pop_front_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 0)
  %1 = bitcast i8* %call4 to i32*
  %2 = load i32* %1, align 4, !tbaa !4
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i32 [ %2, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define internal fastcc noalias i8* @remove_list_element(%struct.list_descriptor* nocapture %desc, i64 %pos) #0 {
entry:
  %list_size = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 3
  %0 = load i64* %list_size, align 8, !tbaa !3
  %cmp = icmp ugt i64 %0, %pos
  br i1 %cmp, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @.str4, i64 0, i64 0), i64 44, i64 1, %struct._IO_FILE* %1)
  tail call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %list_head = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 0
  %3 = load %struct.node_t** %list_head, align 8, !tbaa !0
  %tobool65 = icmp eq %struct.node_t* %3, null
  br i1 %tobool65, label %return, label %while.body

while.cond:                                       ; preds = %while.body
  %inc = add i64 %cnt.067, 1
  %tobool = icmp eq %struct.node_t* %4, null
  br i1 %tobool, label %return, label %while.body

while.body:                                       ; preds = %if.end, %while.cond
  %cnt.067 = phi i64 [ %inc, %while.cond ], [ 0, %if.end ]
  %current.066 = phi %struct.node_t* [ %4, %while.cond ], [ %3, %if.end ]
  %cmp1 = icmp eq i64 %cnt.067, %pos
  %next = getelementptr inbounds %struct.node_t* %current.066, i64 0, i32 1
  %4 = load %struct.node_t** %next, align 8, !tbaa !0
  br i1 %cmp1, label %if.then2, label %while.cond

if.then2:                                         ; preds = %while.body
  %tobool3 = icmp eq %struct.node_t* %4, null
  %prev21 = getelementptr inbounds %struct.node_t* %current.066, i64 0, i32 2
  %5 = load %struct.node_t** %prev21, align 8, !tbaa !0
  %tobool22 = icmp eq %struct.node_t* %5, null
  br i1 %tobool3, label %if.else20, label %land.lhs.true

land.lhs.true:                                    ; preds = %if.then2
  br i1 %tobool22, label %if.then14, label %if.then5

if.then5:                                         ; preds = %land.lhs.true
  %next8 = getelementptr inbounds %struct.node_t* %5, i64 0, i32 1
  store %struct.node_t* %4, %struct.node_t** %next8, align 8, !tbaa !0
  %6 = load %struct.node_t** %prev21, align 8, !tbaa !0
  %7 = load %struct.node_t** %next, align 8, !tbaa !0
  %prev11 = getelementptr inbounds %struct.node_t* %7, i64 0, i32 2
  store %struct.node_t* %6, %struct.node_t** %prev11, align 8, !tbaa !0
  br label %if.end33

if.then14:                                        ; preds = %land.lhs.true
  store %struct.node_t* %4, %struct.node_t** %list_head, align 8, !tbaa !0
  %prev17 = getelementptr inbounds %struct.node_t* %current.066, i64 0, i32 2
  %8 = load %struct.node_t** %prev17, align 8, !tbaa !0
  %9 = load %struct.node_t** %next, align 8, !tbaa !0
  %prev19 = getelementptr inbounds %struct.node_t* %9, i64 0, i32 2
  store %struct.node_t* %8, %struct.node_t** %prev19, align 8, !tbaa !0
  br label %if.end33

if.else20:                                        ; preds = %if.then2
  br i1 %tobool22, label %if.else28, label %if.then23

if.then23:                                        ; preds = %if.else20
  %list_tail = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  store %struct.node_t* %5, %struct.node_t** %list_tail, align 8, !tbaa !0
  %10 = load %struct.node_t** %next, align 8, !tbaa !0
  %11 = load %struct.node_t** %prev21, align 8, !tbaa !0
  %next27 = getelementptr inbounds %struct.node_t* %11, i64 0, i32 1
  store %struct.node_t* %10, %struct.node_t** %next27, align 8, !tbaa !0
  br label %if.end33

if.else28:                                        ; preds = %if.else20
  %12 = bitcast %struct.list_descriptor* %desc to i8*
  call void @llvm.memset.p0i8.i64(i8* %12, i8 0, i64 16, i32 8, i1 false)
  br label %if.end33

if.end33:                                         ; preds = %if.then14, %if.else28, %if.then23, %if.then5
  %value = getelementptr inbounds %struct.node_t* %current.066, i64 0, i32 0
  %13 = load i8** %value, align 8, !tbaa !0
  %type = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 5
  %14 = load i64* %type, align 8, !tbaa !3
  %arrayidx.i.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %14
  %15 = load i64* %arrayidx.i.i, align 8, !tbaa !3
  %call1.i = tail call noalias i8* @malloc(i64 %15) #4
  %tobool.i = icmp eq i8* %call1.i, null
  br i1 %tobool.i, label %if.then.i, label %free_node.exit

if.then.i:                                        ; preds = %if.end33
  %16 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %17 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str3, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %16) #4
  tail call void @exit(i32 1) #6
  unreachable

free_node.exit:                                   ; preds = %if.end33
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %call1.i, i8* %13, i64 %15, i32 1, i1 false) #4
  tail call void @free(i8* %13) #4
  %18 = bitcast %struct.node_t* %current.066 to i8*
  tail call void @free(i8* %18) #4
  %19 = load i64* %list_size, align 8, !tbaa !3
  %dec = add i64 %19, -1
  store i64 %dec, i64* %list_size, align 8, !tbaa !3
  br label %return

return:                                           ; preds = %if.end, %while.cond, %free_node.exit
  %retval.0 = phi i8* [ %call1.i, %free_node.exit ], [ null, %while.cond ], [ null, %if.end ]
  ret i8* %retval.0
}

; Function Attrs: nounwind uwtable
define float @list_pop_front_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 0)
  %1 = bitcast i8* %call4 to float*
  %2 = load float* %1, align 4, !tbaa !5
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi float [ %2, %if.end3 ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_pop_front_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 0)
  %1 = load i8* %call4, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %1, 0
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i1 [ %tobool5, %if.end3 ], [ false, %entry ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @list_pop_front_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 0)
  %1 = load i8* %call4, align 1, !tbaa !1
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i8 [ %1, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_pop_front_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 0)
  %1 = bitcast i8* %call4 to i64*
  %2 = load i64* %1, align 8, !tbaa !3
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i64 [ %2, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i32 @list_pop_back_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %sub = add i64 %1, -1
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %sub)
  %2 = bitcast i8* %call4 to i32*
  %3 = load i32* %2, align 4, !tbaa !4
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i32 [ %3, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @list_pop_back_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %sub = add i64 %1, -1
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %sub)
  %2 = bitcast i8* %call4 to float*
  %3 = load float* %2, align 4, !tbaa !5
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi float [ %3, %if.end3 ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_pop_back_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %sub = add i64 %1, -1
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %sub)
  %2 = load i8* %call4, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %2, 0
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i1 [ %tobool5, %if.end3 ], [ false, %entry ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @list_pop_back_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %sub = add i64 %1, -1
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %sub)
  %2 = load i8* %call4, align 1, !tbaa !1
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i8 [ %2, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_pop_back_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %sub = add i64 %1, -1
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %sub)
  %2 = bitcast i8* %call4 to i64*
  %3 = load i64* %2, align 8, !tbaa !3
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i64 [ %3, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define void @list_push_front_int(%struct.list_table* %table, i64 %lid, i32 %value) #0 {
entry:
  %value.addr = alloca i32, align 4
  store i32 %value, i32* %value.addr, align 4, !tbaa !4
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %1 = bitcast i32* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 0, i8* %1)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define internal fastcc void @insert_list_element(%struct.list_descriptor* nocapture %desc, i64 %pos, i8* nocapture %elem) #0 {
entry:
  %list_size = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 3
  %0 = load i64* %list_size, align 8, !tbaa !3
  %cmp = icmp ult i64 %0, %pos
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @.str1, i64 0, i64 0), i64 44, i64 1, %struct._IO_FILE* %1)
  tail call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %cmp2 = icmp eq i64 %0, %pos
  br i1 %cmp2, label %if.then3, label %if.end12

if.then3:                                         ; preds = %if.end
  %type = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 5
  %3 = load i64* %type, align 8, !tbaa !3
  %call4 = tail call fastcc %struct.node_t* @create_node(i8* %elem, i64 %3)
  %4 = load i64* %list_size, align 8, !tbaa !3
  %cmp6 = icmp eq i64 %4, 0
  br i1 %cmp6, label %if.then7, label %if.else

if.then7:                                         ; preds = %if.then3
  %list_head = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 0
  store %struct.node_t* %call4, %struct.node_t** %list_head, align 8, !tbaa !0
  %list_tail9.pre = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  br label %if.end8

if.else:                                          ; preds = %if.then3
  %list_tail = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 1
  %5 = load %struct.node_t** %list_tail, align 8, !tbaa !0
  %next = getelementptr inbounds %struct.node_t* %5, i64 0, i32 1
  store %struct.node_t* %call4, %struct.node_t** %next, align 8, !tbaa !0
  br label %if.end8

if.end8:                                          ; preds = %if.else, %if.then7
  %list_tail9.pre-phi = phi %struct.node_t** [ %list_tail, %if.else ], [ %list_tail9.pre, %if.then7 ]
  %6 = load %struct.node_t** %list_tail9.pre-phi, align 8, !tbaa !0
  %prev = getelementptr inbounds %struct.node_t* %call4, i64 0, i32 2
  store %struct.node_t* %6, %struct.node_t** %prev, align 8, !tbaa !0
  store %struct.node_t* %call4, %struct.node_t** %list_tail9.pre-phi, align 8, !tbaa !0
  %inc = add i64 %4, 1
  store i64 %inc, i64* %list_size, align 8, !tbaa !3
  br label %while.end

if.end12:                                         ; preds = %if.end
  %list_head13 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 0
  %current.083 = load %struct.node_t** %list_head13, align 8
  %tobool84 = icmp eq %struct.node_t* %current.083, null
  br i1 %tobool84, label %while.end, label %while.body

while.body:                                       ; preds = %if.end12, %if.end45
  %current.086 = phi %struct.node_t* [ %current.0, %if.end45 ], [ %current.083, %if.end12 ]
  %cnt.085 = phi i64 [ %inc14, %if.end45 ], [ 0, %if.end12 ]
  %cmp15 = icmp eq i64 %cnt.085, %pos
  br i1 %cmp15, label %if.then16, label %if.end45

if.then16:                                        ; preds = %while.body
  %type18 = getelementptr inbounds %struct.list_descriptor* %desc, i64 0, i32 5
  %7 = load i64* %type18, align 8, !tbaa !3
  %call19 = tail call fastcc %struct.node_t* @create_node(i8* %elem, i64 %7)
  %prev20 = getelementptr inbounds %struct.node_t* %current.086, i64 0, i32 2
  %8 = load %struct.node_t** %prev20, align 8, !tbaa !0
  %tobool21 = icmp eq %struct.node_t* %8, null
  %prev24 = getelementptr inbounds %struct.node_t* %call19, i64 0, i32 2
  store %struct.node_t* %8, %struct.node_t** %prev24, align 8, !tbaa !0
  %next25 = getelementptr inbounds %struct.node_t* %call19, i64 0, i32 1
  store %struct.node_t* %current.086, %struct.node_t** %next25, align 8, !tbaa !0
  br i1 %tobool21, label %if.then32, label %if.then22

if.then22:                                        ; preds = %if.then16
  %9 = load %struct.node_t** %prev20, align 8, !tbaa !0
  %next27 = getelementptr inbounds %struct.node_t* %9, i64 0, i32 1
  store %struct.node_t* %call19, %struct.node_t** %next27, align 8, !tbaa !0
  br label %if.end42

if.then32:                                        ; preds = %if.then16
  store %struct.node_t* %call19, %struct.node_t** %list_head13, align 8, !tbaa !0
  br label %if.end42

if.end42:                                         ; preds = %if.then32, %if.then22
  store %struct.node_t* %call19, %struct.node_t** %prev20, align 8, !tbaa !0
  %10 = load i64* %list_size, align 8, !tbaa !3
  %inc44 = add i64 %10, 1
  store i64 %inc44, i64* %list_size, align 8, !tbaa !3
  br label %while.end

if.end45:                                         ; preds = %while.body
  %inc14 = add i64 %cnt.085, 1
  %next46 = getelementptr inbounds %struct.node_t* %current.086, i64 0, i32 1
  %current.0 = load %struct.node_t** %next46, align 8
  %tobool = icmp eq %struct.node_t* %current.0, null
  br i1 %tobool, label %while.end, label %while.body

while.end:                                        ; preds = %if.end12, %if.end45, %if.end8, %if.end42
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_float(%struct.list_table* %table, i64 %lid, float %value) #0 {
entry:
  %value.addr = alloca float, align 4
  store float %value, float* %value.addr, align 4, !tbaa !5
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %1 = bitcast float* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 0, i8* %1)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_bool(%struct.list_table* %table, i64 %lid, i1 zeroext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1, !tbaa !6
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 0, i8* %value.addr)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_char(%struct.list_table* %table, i64 %lid, i8 signext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  store i8 %value, i8* %value.addr, align 1, !tbaa !1
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 0, i8* %value.addr)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_string(%struct.list_table* %table, i64 %lid, i64 %value) #0 {
entry:
  %value.addr = alloca i64, align 8
  store i64 %value, i64* %value.addr, align 8, !tbaa !3
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %1 = bitcast i64* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 0, i8* %1)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_int(%struct.list_table* %table, i64 %lid, i32 %value) #0 {
entry:
  %value.addr = alloca i32, align 4
  store i32 %value, i32* %value.addr, align 4, !tbaa !4
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %2 = bitcast i32* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %1, i8* %2)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_float(%struct.list_table* %table, i64 %lid, float %value) #0 {
entry:
  %value.addr = alloca float, align 4
  store float %value, float* %value.addr, align 4, !tbaa !5
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %2 = bitcast float* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %1, i8* %2)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_bool(%struct.list_table* %table, i64 %lid, i1 zeroext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1, !tbaa !6
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %1, i8* %value.addr)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_char(%struct.list_table* %table, i64 %lid, i8 signext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  store i8 %value, i8* %value.addr, align 1, !tbaa !1
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %1, i8* %value.addr)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_string(%struct.list_table* %table, i64 %lid, i64 %value) #0 {
entry:
  %value.addr = alloca i64, align 8
  store i64 %value, i64* %value.addr, align 8, !tbaa !3
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size, align 8, !tbaa !3
  %2 = bitcast i64* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %1, i8* %2)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @list_get_element_int(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp ugt i64 %1, %pos
  br i1 %cmp.i7, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i18 = icmp eq i64 %pos, 0
  br i1 %cmp1.i18, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i17, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = bitcast i8* %4 to i32*
  %6 = load i32* %5, align 4, !tbaa !4
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i20 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i17, %if.end.i ]
  %cnt.010.i19 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i19, 1
  %next.i9 = getelementptr inbounds %struct.node_t* %current.011.i20, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i9, align 8
  %cmp1.i = icmp eq i64 %inc.i, %pos
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i32 [ %6, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @list_get_element_float(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp ugt i64 %1, %pos
  br i1 %cmp.i7, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i18 = icmp eq i64 %pos, 0
  br i1 %cmp1.i18, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i17, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = bitcast i8* %4 to float*
  %6 = load float* %5, align 4, !tbaa !5
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i20 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i17, %if.end.i ]
  %cnt.010.i19 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i19, 1
  %next.i9 = getelementptr inbounds %struct.node_t* %current.011.i20, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i9, align 8
  %cmp1.i = icmp eq i64 %inc.i, %pos
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi float [ %6, %if.then2.i ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_get_element_bool(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i8 = icmp ugt i64 %1, %pos
  br i1 %cmp.i8, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i18 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i19 = icmp eq i64 %pos, 0
  br i1 %cmp1.i19, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i18, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = load i8* %4, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %5, 0
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i21 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i18, %if.end.i ]
  %cnt.010.i20 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i20, 1
  %next.i10 = getelementptr inbounds %struct.node_t* %current.011.i21, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i10, align 8
  %cmp1.i = icmp eq i64 %inc.i, %pos
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i1 [ %tobool5, %if.then2.i ], [ false, %entry ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @list_get_element_char(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp ugt i64 %1, %pos
  br i1 %cmp.i7, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i18 = icmp eq i64 %pos, 0
  br i1 %cmp1.i18, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i17, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = load i8* %4, align 1, !tbaa !1
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i20 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i17, %if.end.i ]
  %cnt.010.i19 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i19, 1
  %next.i9 = getelementptr inbounds %struct.node_t* %current.011.i20, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i9, align 8
  %cmp1.i = icmp eq i64 %inc.i, %pos
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i8 [ %5, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_get_element_string(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  %cmp.i7 = icmp ugt i64 %1, %pos
  br i1 %cmp.i7, label %if.end.i, label %if.then.i

if.then.i:                                        ; preds = %if.end3
  %2 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %3 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str5, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %2) #4
  tail call void @exit(i32 1) #6
  unreachable

if.end.i:                                         ; preds = %if.end3
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 0
  %current.011.i17 = load %struct.node_t** %list_head.i, align 8
  %cmp1.i18 = icmp eq i64 %pos, 0
  br i1 %cmp1.i18, label %if.then2.i, label %if.end3.i

if.then2.i:                                       ; preds = %if.end3.i, %if.end.i
  %current.011.i.lcssa = phi %struct.node_t* [ %current.011.i17, %if.end.i ], [ %current.011.i, %if.end3.i ]
  %value.i = getelementptr inbounds %struct.node_t* %current.011.i.lcssa, i64 0, i32 0
  %4 = load i8** %value.i, align 8, !tbaa !0
  %5 = bitcast i8* %4 to i64*
  %6 = load i64* %5, align 8, !tbaa !3
  br label %return

if.end3.i:                                        ; preds = %if.end.i, %if.end3.i
  %current.011.i20 = phi %struct.node_t* [ %current.011.i, %if.end3.i ], [ %current.011.i17, %if.end.i ]
  %cnt.010.i19 = phi i64 [ %inc.i, %if.end3.i ], [ 0, %if.end.i ]
  %inc.i = add i64 %cnt.010.i19, 1
  %next.i9 = getelementptr inbounds %struct.node_t* %current.011.i20, i64 0, i32 1
  %current.011.i = load %struct.node_t** %next.i9, align 8
  %cmp1.i = icmp eq i64 %inc.i, %pos
  br i1 %cmp1.i, label %if.then2.i, label %if.end3.i

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.then2.i
  %retval.0 = phi i64 [ %6, %if.then2.i ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_int(%struct.list_table* %table, i64 %lid, i64 %pos, i32 %value) #0 {
entry:
  %value.addr = alloca i32, align 4
  store i32 %value, i32* %value.addr, align 4, !tbaa !4
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %1 = bitcast i32* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %pos, i8* %1)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_float(%struct.list_table* %table, i64 %lid, i64 %pos, float %value) #0 {
entry:
  %value.addr = alloca float, align 4
  store float %value, float* %value.addr, align 4, !tbaa !5
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %1 = bitcast float* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %pos, i8* %1)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_bool(%struct.list_table* %table, i64 %lid, i64 %pos, i1 zeroext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1, !tbaa !6
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %pos, i8* %value.addr)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_char(%struct.list_table* %table, i64 %lid, i64 %pos, i8 signext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  store i8 %value, i8* %value.addr, align 1, !tbaa !1
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %pos, i8* %value.addr)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_string(%struct.list_table* %table, i64 %lid, i64 %pos, i64 %value) #0 {
entry:
  %value.addr = alloca i64, align 8
  store i64 %value, i64* %value.addr, align 8, !tbaa !3
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %1 = bitcast i64* %value.addr to i8*
  call fastcc void @insert_list_element(%struct.list_descriptor* %current.05.i, i64 %pos, i8* %1)
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @list_remove_element_int(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %pos)
  %1 = bitcast i8* %call4 to i32*
  %2 = load i32* %1, align 4, !tbaa !4
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i32 [ %2, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @list_remove_element_float(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %pos)
  %1 = bitcast i8* %call4 to float*
  %2 = load float* %1, align 4, !tbaa !5
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi float [ %2, %if.end3 ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_remove_element_bool(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %pos)
  %1 = load i8* %call4, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %1, 0
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i1 [ %tobool5, %if.end3 ], [ false, %entry ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @list_remove_element_char(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %pos)
  %1 = load i8* %call4, align 1, !tbaa !1
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i8 [ %1, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_remove_element_string(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.list_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i = load %struct.list_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.list_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %0 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %0, %lid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %call4 = tail call fastcc i8* @remove_list_element(%struct.list_descriptor* %current.05.i, i64 %pos)
  %1 = bitcast i8* %call4 to i64*
  %2 = load i64* %1, align 8, !tbaa !3
  tail call void @free(i8* %call4) #4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i64 [ %2, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @list_make_sequence(%struct.list_table* %table, i64 %a, i64 %b) #0 {
entry:
  %i = alloca i64, align 8
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %find_descriptor.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %0 = load i64* @list_counter, align 8, !tbaa !3
  %inc.i.i = add i64 %0, 1
  store i64 %inc.i.i, i64* @list_counter, align 8, !tbaa !3
  %call.i.i = call noalias i8* @malloc(i64 56) #4
  %tobool.i.i = icmp eq i8* %call.i.i, null
  br i1 %tobool.i.i, label %if.then.i.i, label %list_allocate_int.exit

if.then.i.i:                                      ; preds = %if.end.i
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %2 = call i64 @fwrite(i8* getelementptr inbounds ([50 x i8]* @.str6, i64 0, i64 0), i64 49, i64 1, %struct._IO_FILE* %1) #4
  call void @exit(i32 1) #6
  unreachable

list_allocate_int.exit:                           ; preds = %if.end.i
  %3 = bitcast i8* %call.i.i to %struct.list_descriptor*
  %list_id.i.i = getelementptr inbounds i8* %call.i.i, i64 16
  %4 = bitcast i8* %list_id.i.i to i64*
  store i64 %0, i64* %4, align 8, !tbaa !3
  %list_size.i.i = getelementptr inbounds i8* %call.i.i, i64 24
  %next.i4.i = getelementptr inbounds i8* %call.i.i, i64 48
  %5 = bitcast i8* %next.i4.i to %struct.list_descriptor**
  call void @llvm.memset.p0i8.i64(i8* %call.i.i, i8 0, i64 16, i32 8, i1 false) #4
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  call void @llvm.memset.p0i8.i64(i8* %list_size.i.i, i8 0, i64 24, i32 8, i1 false) #4
  %6 = load %struct.list_descriptor** %head.i.i, align 8, !tbaa !0
  store %struct.list_descriptor* %6, %struct.list_descriptor** %5, align 8, !tbaa !0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head.i.i, align 8, !tbaa !0
  %tobool4.i = icmp eq i8* %call.i.i, null
  br i1 %tobool4.i, label %find_descriptor.exit, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 6
  %current.0.i = load %struct.list_descriptor** %next.i, align 8
  %tobool.i5 = icmp eq %struct.list_descriptor* %current.0.i, null
  br i1 %tobool.i5, label %find_descriptor.exit, label %while.body.i

while.body.i:                                     ; preds = %list_allocate_int.exit, %while.cond.i
  %current.05.i = phi %struct.list_descriptor* [ %current.0.i, %while.cond.i ], [ %3, %list_allocate_int.exit ]
  %list_id.i = getelementptr inbounds %struct.list_descriptor* %current.05.i, i64 0, i32 2
  %7 = load i64* %list_id.i, align 8, !tbaa !3
  %cmp.i = icmp eq i64 %7, %0
  br i1 %cmp.i, label %find_descriptor.exit, label %while.cond.i

find_descriptor.exit:                             ; preds = %entry, %while.cond.i, %while.body.i, %list_allocate_int.exit
  %retval.0.i10 = phi i64 [ %0, %list_allocate_int.exit ], [ %0, %while.body.i ], [ %0, %while.cond.i ], [ 0, %entry ]
  %retval.0.i6 = phi %struct.list_descriptor* [ null, %list_allocate_int.exit ], [ %current.05.i, %while.body.i ], [ null, %while.cond.i ], [ null, %entry ]
  store i64 %a, i64* %i, align 8, !tbaa !3
  %cmp7 = icmp ugt i64 %a, %b
  br i1 %cmp7, label %for.end, label %for.body.lr.ph

for.body.lr.ph:                                   ; preds = %find_descriptor.exit
  %list_size = getelementptr inbounds %struct.list_descriptor* %retval.0.i6, i64 0, i32 3
  %8 = bitcast i64* %i to i8*
  br label %for.body

for.body:                                         ; preds = %for.body.lr.ph, %for.body
  %9 = load i64* %list_size, align 8, !tbaa !3
  call fastcc void @insert_list_element(%struct.list_descriptor* %retval.0.i6, i64 %9, i8* %8)
  %10 = load i64* %i, align 8, !tbaa !3
  %inc = add i64 %10, 1
  store i64 %inc, i64* %i, align 8, !tbaa !3
  %cmp = icmp ugt i64 %inc, %b
  br i1 %cmp, label %for.end, label %for.body

for.end:                                          ; preds = %for.body, %find_descriptor.exit
  ret i64 %retval.0.i10
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @list_empty_int(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i.i, label %list_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.list_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.list_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %list_id.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i.i, align 8, !tbaa !3
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %list_size.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i.i, align 8, !tbaa !3
  %phitmp.i = icmp eq i64 %1, 0
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @list_empty_bool(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i.i, label %list_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.list_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.list_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %list_id.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i.i, align 8, !tbaa !3
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %list_size.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i.i, align 8, !tbaa !3
  %phitmp.i = icmp eq i64 %1, 0
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @list_empty_float(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i.i, label %list_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.list_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.list_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %list_id.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i.i, align 8, !tbaa !3
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %list_size.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i.i, align 8, !tbaa !3
  %phitmp.i = icmp eq i64 %1, 0
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @list_empty_string(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i.i, label %list_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.list_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.list_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %list_id.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i.i, align 8, !tbaa !3
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %list_size.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i.i, align 8, !tbaa !3
  %phitmp.i = icmp eq i64 %1, 0
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @list_empty_char(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i.i, label %list_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.list_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.list_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 6
  %current.0.i.i.i = load %struct.list_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.list_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %list_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.list_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %list_id.i.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i.i, align 8, !tbaa !3
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %list_size.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i.i, align 8, !tbaa !3
  %phitmp.i = icmp eq i64 %1, 0
  br label %list_empty.exit

list_empty.exit:                                  ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind uwtable
define void @list_clear_int(%struct.list_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 0
  %1 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool4.i = icmp eq %struct.node_t* %1, null
  br i1 %tobool4.i, label %list_clear.exit, label %if.end6.i

if.end6.i:                                        ; preds = %if.end3.i
  %prev1.i.i = getelementptr inbounds %struct.node_t* %1, i64 0, i32 2
  %2 = load %struct.node_t** %prev1.i.i, align 8, !tbaa !0
  %tobool.i16.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool.i16.i, label %free_node.exit.i.i, label %while.cond.preheader.i.i

while.cond.preheader.i.i:                         ; preds = %if.end6.i
  %next.i17.i = getelementptr inbounds %struct.node_t* %2, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next.i17.i, align 8, !tbaa !0
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %while.cond.preheader.i.i, %if.end6.i, %free_node.exit.i.i
  %node.addr.011.i.i = phi %struct.node_t* [ %3, %free_node.exit.i.i ], [ %1, %if.end6.i ], [ %1, %while.cond.preheader.i.i ]
  %next4.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 1
  %3 = load %struct.node_t** %next4.i.i, align 8, !tbaa !0
  %value.i.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 0
  %4 = load i8** %value.i.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %node.addr.011.i.i to i8*
  tail call void @free(i8* %5) #4
  %tobool2.i.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool2.i.i, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %list_tail.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 1
  store %struct.node_t* %2, %struct.node_t** %list_tail.i, align 8, !tbaa !0
  store %struct.node_t* %2, %struct.node_t** %list_head.i, align 8, !tbaa !0
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  store i64 0, i64* %list_size.i, align 8, !tbaa !3
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_clear_bool(%struct.list_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 0
  %1 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool4.i = icmp eq %struct.node_t* %1, null
  br i1 %tobool4.i, label %list_clear.exit, label %if.end6.i

if.end6.i:                                        ; preds = %if.end3.i
  %prev1.i.i = getelementptr inbounds %struct.node_t* %1, i64 0, i32 2
  %2 = load %struct.node_t** %prev1.i.i, align 8, !tbaa !0
  %tobool.i16.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool.i16.i, label %free_node.exit.i.i, label %while.cond.preheader.i.i

while.cond.preheader.i.i:                         ; preds = %if.end6.i
  %next.i17.i = getelementptr inbounds %struct.node_t* %2, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next.i17.i, align 8, !tbaa !0
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %while.cond.preheader.i.i, %if.end6.i, %free_node.exit.i.i
  %node.addr.011.i.i = phi %struct.node_t* [ %3, %free_node.exit.i.i ], [ %1, %if.end6.i ], [ %1, %while.cond.preheader.i.i ]
  %next4.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 1
  %3 = load %struct.node_t** %next4.i.i, align 8, !tbaa !0
  %value.i.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 0
  %4 = load i8** %value.i.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %node.addr.011.i.i to i8*
  tail call void @free(i8* %5) #4
  %tobool2.i.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool2.i.i, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %list_tail.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 1
  store %struct.node_t* %2, %struct.node_t** %list_tail.i, align 8, !tbaa !0
  store %struct.node_t* %2, %struct.node_t** %list_head.i, align 8, !tbaa !0
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  store i64 0, i64* %list_size.i, align 8, !tbaa !3
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_clear_float(%struct.list_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 0
  %1 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool4.i = icmp eq %struct.node_t* %1, null
  br i1 %tobool4.i, label %list_clear.exit, label %if.end6.i

if.end6.i:                                        ; preds = %if.end3.i
  %prev1.i.i = getelementptr inbounds %struct.node_t* %1, i64 0, i32 2
  %2 = load %struct.node_t** %prev1.i.i, align 8, !tbaa !0
  %tobool.i16.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool.i16.i, label %free_node.exit.i.i, label %while.cond.preheader.i.i

while.cond.preheader.i.i:                         ; preds = %if.end6.i
  %next.i17.i = getelementptr inbounds %struct.node_t* %2, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next.i17.i, align 8, !tbaa !0
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %while.cond.preheader.i.i, %if.end6.i, %free_node.exit.i.i
  %node.addr.011.i.i = phi %struct.node_t* [ %3, %free_node.exit.i.i ], [ %1, %if.end6.i ], [ %1, %while.cond.preheader.i.i ]
  %next4.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 1
  %3 = load %struct.node_t** %next4.i.i, align 8, !tbaa !0
  %value.i.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 0
  %4 = load i8** %value.i.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %node.addr.011.i.i to i8*
  tail call void @free(i8* %5) #4
  %tobool2.i.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool2.i.i, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %list_tail.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 1
  store %struct.node_t* %2, %struct.node_t** %list_tail.i, align 8, !tbaa !0
  store %struct.node_t* %2, %struct.node_t** %list_head.i, align 8, !tbaa !0
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  store i64 0, i64* %list_size.i, align 8, !tbaa !3
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_clear_string(%struct.list_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 0
  %1 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool4.i = icmp eq %struct.node_t* %1, null
  br i1 %tobool4.i, label %list_clear.exit, label %if.end6.i

if.end6.i:                                        ; preds = %if.end3.i
  %prev1.i.i = getelementptr inbounds %struct.node_t* %1, i64 0, i32 2
  %2 = load %struct.node_t** %prev1.i.i, align 8, !tbaa !0
  %tobool.i16.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool.i16.i, label %free_node.exit.i.i, label %while.cond.preheader.i.i

while.cond.preheader.i.i:                         ; preds = %if.end6.i
  %next.i17.i = getelementptr inbounds %struct.node_t* %2, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next.i17.i, align 8, !tbaa !0
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %while.cond.preheader.i.i, %if.end6.i, %free_node.exit.i.i
  %node.addr.011.i.i = phi %struct.node_t* [ %3, %free_node.exit.i.i ], [ %1, %if.end6.i ], [ %1, %while.cond.preheader.i.i ]
  %next4.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 1
  %3 = load %struct.node_t** %next4.i.i, align 8, !tbaa !0
  %value.i.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 0
  %4 = load i8** %value.i.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %node.addr.011.i.i to i8*
  tail call void @free(i8* %5) #4
  %tobool2.i.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool2.i.i, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %list_tail.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 1
  store %struct.node_t* %2, %struct.node_t** %list_tail.i, align 8, !tbaa !0
  store %struct.node_t* %2, %struct.node_t** %list_head.i, align 8, !tbaa !0
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  store i64 0, i64* %list_size.i, align 8, !tbaa !3
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_clear_char(%struct.list_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_head.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 0
  %1 = load %struct.node_t** %list_head.i, align 8, !tbaa !0
  %tobool4.i = icmp eq %struct.node_t* %1, null
  br i1 %tobool4.i, label %list_clear.exit, label %if.end6.i

if.end6.i:                                        ; preds = %if.end3.i
  %prev1.i.i = getelementptr inbounds %struct.node_t* %1, i64 0, i32 2
  %2 = load %struct.node_t** %prev1.i.i, align 8, !tbaa !0
  %tobool.i16.i = icmp eq %struct.node_t* %2, null
  br i1 %tobool.i16.i, label %free_node.exit.i.i, label %while.cond.preheader.i.i

while.cond.preheader.i.i:                         ; preds = %if.end6.i
  %next.i17.i = getelementptr inbounds %struct.node_t* %2, i64 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next.i17.i, align 8, !tbaa !0
  br label %free_node.exit.i.i

free_node.exit.i.i:                               ; preds = %while.cond.preheader.i.i, %if.end6.i, %free_node.exit.i.i
  %node.addr.011.i.i = phi %struct.node_t* [ %3, %free_node.exit.i.i ], [ %1, %if.end6.i ], [ %1, %while.cond.preheader.i.i ]
  %next4.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 1
  %3 = load %struct.node_t** %next4.i.i, align 8, !tbaa !0
  %value.i.i.i = getelementptr inbounds %struct.node_t* %node.addr.011.i.i, i64 0, i32 0
  %4 = load i8** %value.i.i.i, align 8, !tbaa !0
  tail call void @free(i8* %4) #4
  %5 = bitcast %struct.node_t* %node.addr.011.i.i to i8*
  tail call void @free(i8* %5) #4
  %tobool2.i.i = icmp eq %struct.node_t* %3, null
  br i1 %tobool2.i.i, label %free_node_recur.exit.i, label %free_node.exit.i.i

free_node_recur.exit.i:                           ; preds = %free_node.exit.i.i
  %list_tail.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 1
  store %struct.node_t* %2, %struct.node_t** %list_tail.i, align 8, !tbaa !0
  store %struct.node_t* %2, %struct.node_t** %list_head.i, align 8, !tbaa !0
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  store i64 0, i64* %list_size.i, align 8, !tbaa !3
  br label %list_clear.exit

list_clear.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i, %free_node_recur.exit.i
  ret void
}

; Function Attrs: nounwind readonly uwtable
define i64 @list_size_int(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  br label %list_size.exit

list_size.exit:                                   ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @list_size_bool(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  br label %list_size.exit

list_size.exit:                                   ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @list_size_float(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  br label %list_size.exit

list_size.exit:                                   ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @list_size_string(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  br label %list_size.exit

list_size.exit:                                   ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @list_size_char(%struct.list_table* %table, i64 %id) #3 {
entry:
  %tobool.i = icmp eq %struct.list_table* %table, null
  br i1 %tobool.i, label %list_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.list_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.list_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.list_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %list_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 6
  %current.0.i.i = load %struct.list_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.list_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %list_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.list_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %list_id.i.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 2
  %0 = load i64* %list_id.i.i, align 8, !tbaa !3
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %list_size.i = getelementptr inbounds %struct.list_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i64* %list_size.i, align 8, !tbaa !3
  br label %list_size.exit

list_size.exit:                                   ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind uwtable
define internal fastcc noalias %struct.node_t* @create_node(i8* nocapture %value, i64 %type) #0 {
entry:
  %call = tail call noalias i8* @malloc(i64 24) #4
  %tobool = icmp eq i8* %call, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %0 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %1 = tail call i64 @fwrite(i8* getelementptr inbounds ([44 x i8]* @.str2, i64 0, i64 0), i64 43, i64 1, %struct._IO_FILE* %0)
  tail call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %next2 = getelementptr inbounds i8* %call, i64 8
  %arrayidx.i.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %type
  call void @llvm.memset.p0i8.i64(i8* %next2, i8 0, i64 16, i32 8, i1 false)
  %2 = load i64* %arrayidx.i.i, align 8, !tbaa !3
  %call1.i = tail call noalias i8* @malloc(i64 %2) #4
  %tobool.i = icmp eq i8* %call1.i, null
  br i1 %tobool.i, label %if.then.i, label %cpy_value.exit

if.then.i:                                        ; preds = %if.end
  %3 = load %struct._IO_FILE** @stderr, align 8, !tbaa !0
  %4 = tail call i64 @fwrite(i8* getelementptr inbounds ([42 x i8]* @.str3, i64 0, i64 0), i64 41, i64 1, %struct._IO_FILE* %3) #4
  tail call void @exit(i32 1) #6
  unreachable

cpy_value.exit:                                   ; preds = %if.end
  %5 = bitcast i8* %call to %struct.node_t*
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %call1.i, i8* %value, i64 %2, i32 1, i1 false) #4
  %value5 = bitcast i8* %call to i8**
  store i8* %call1.i, i8** %value5, align 8, !tbaa !0
  ret %struct.node_t* %5
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) #4

; Function Attrs: nounwind
declare i64 @fwrite(i8* nocapture, i64, i64, %struct._IO_FILE* nocapture) #4

; Function Attrs: nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #4

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.uadd.with.overflow.i64(i64, i64) #5

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind readonly uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { nounwind readnone }
attributes #6 = { noreturn nounwind }

!0 = metadata !{metadata !"any pointer", metadata !1}
!1 = metadata !{metadata !"omnipotent char", metadata !2}
!2 = metadata !{metadata !"Simple C/C++ TBAA"}
!3 = metadata !{metadata !"long", metadata !1}
!4 = metadata !{metadata !"int", metadata !1}
!5 = metadata !{metadata !"float", metadata !1}
!6 = metadata !{metadata !"_Bool", metadata !1}
!7 = metadata !{i8 0, i8 2}
