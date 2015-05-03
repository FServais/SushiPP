; ModuleID = 'array_runtime.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.array_table = type { %struct.array_descriptor* }
%struct.array_descriptor = type { i64, i64, i64, i8*, i64, %struct.array_descriptor* }

@bytes_per_type = global [5 x i64] [i64 4, i64 4, i64 1, i64 1, i64 8], align 16
@stderr = external global %struct._IO_FILE*
@.str = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `create_array_table`\0A\00", align 1
@.str1 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `array_remove_value`\0A\00", align 1
@.str2 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `array_insert_value`\0A\00", align 1
@.str3 = private unnamed_addr constant [53 x i8] c"Memory allocation failure in `new_array_descriptor`\0A\00", align 1
@array_counter = internal global i64 1, align 8

; Function Attrs: nounwind uwtable
define i64 @array_allocate_int(%struct.array_table* %table, i64 %size, i32* %populate) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %size.addr = alloca i64, align 8
  %populate.addr = alloca i32*, align 8
  %array_id = alloca i64, align 8
  %new_desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  store i32* %populate, i32** %populate.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @create_unique_id()
  store i64 %call, i64* %array_id, align 8
  %1 = load i64* %array_id, align 8
  %2 = load i64* %size.addr, align 8
  %call1 = call %struct.array_descriptor* @new_array_descriptor(i64 %1, i64 %2, i64 0, i64 0)
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %new_desc, align 8
  %3 = load %struct.array_table** %table.addr, align 8
  %4 = load %struct.array_descriptor** %new_desc, align 8
  call void @insert_descriptor(%struct.array_table* %3, %struct.array_descriptor* %4)
  %5 = load %struct.array_descriptor** %new_desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %5, i32 0, i32 3
  %6 = load i8** %array_ptr, align 8
  %7 = load i32** %populate.addr, align 8
  %8 = bitcast i32* %7 to i8*
  %9 = load i64* %size.addr, align 8
  %mul = mul i64 %9, 4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %8, i64 %mul, i32 1, i1 false)
  %10 = load i64* %array_id, align 8
  store i64 %10, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %11 = load i64* %retval
  ret i64 %11
}

; Function Attrs: nounwind uwtable
define internal %struct.array_descriptor* @new_array_descriptor(i64 %id, i64 %size, i64 %type, i64 %ref_count) #0 {
entry:
  %id.addr = alloca i64, align 8
  %size.addr = alloca i64, align 8
  %type.addr = alloca i64, align 8
  %ref_count.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store i64 %id, i64* %id.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  store i64 %type, i64* %type.addr, align 8
  store i64 %ref_count, i64* %ref_count.addr, align 8
  %call = call noalias i8* @malloc(i64 48) #2
  %0 = bitcast i8* %call to %struct.array_descriptor*
  store %struct.array_descriptor* %0, %struct.array_descriptor** %desc, align 8
  %1 = load %struct.array_descriptor** %desc, align 8
  %tobool = icmp ne %struct.array_descriptor* %1, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE** @stderr, align 8
  %call1 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([53 x i8]* @.str3, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %3 = load i64* %id.addr, align 8
  %4 = load %struct.array_descriptor** %desc, align 8
  %array_id = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 0
  store i64 %3, i64* %array_id, align 8
  %5 = load i64* %size.addr, align 8
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  store i64 %5, i64* %array_size, align 8
  %7 = load i64* %ref_count.addr, align 8
  %8 = load %struct.array_descriptor** %desc, align 8
  %ref_count2 = getelementptr inbounds %struct.array_descriptor* %8, i32 0, i32 4
  store i64 %7, i64* %ref_count2, align 8
  %9 = load i64* %type.addr, align 8
  %10 = load %struct.array_descriptor** %desc, align 8
  %type3 = getelementptr inbounds %struct.array_descriptor* %10, i32 0, i32 2
  store i64 %9, i64* %type3, align 8
  %11 = load %struct.array_descriptor** %desc, align 8
  %next = getelementptr inbounds %struct.array_descriptor* %11, i32 0, i32 5
  store %struct.array_descriptor* null, %struct.array_descriptor** %next, align 8
  %12 = load i64* %size.addr, align 8
  %cmp = icmp eq i64 %12, 0
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.end
  br label %cond.end

cond.false:                                       ; preds = %if.end
  %13 = load i64* %size.addr, align 8
  %14 = load i64* %type.addr, align 8
  %call4 = call i64 @num_bytes(i64 %14)
  %mul = mul i64 %13, %call4
  %call5 = call noalias i8* @malloc(i64 %mul) #2
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i8* [ null, %cond.true ], [ %call5, %cond.false ]
  %15 = load %struct.array_descriptor** %desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %15, i32 0, i32 3
  store i8* %cond, i8** %array_ptr, align 8
  %16 = load %struct.array_descriptor** %desc, align 8
  %array_ptr6 = getelementptr inbounds %struct.array_descriptor* %16, i32 0, i32 3
  %17 = load i8** %array_ptr6, align 8
  %tobool7 = icmp ne i8* %17, null
  br i1 %tobool7, label %if.end10, label %if.then8

if.then8:                                         ; preds = %cond.end
  %18 = load %struct._IO_FILE** @stderr, align 8
  %call9 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %18, i8* getelementptr inbounds ([53 x i8]* @.str3, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

if.end10:                                         ; preds = %cond.end
  %19 = load %struct.array_descriptor** %desc, align 8
  ret %struct.array_descriptor* %19
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @insert_descriptor(%struct.array_table* %table, %struct.array_descriptor* %desc) #1 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %desc.addr = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store %struct.array_descriptor* %desc, %struct.array_descriptor** %desc.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.array_table* %0, i32 0, i32 0
  %1 = load %struct.array_descriptor** %head, align 8
  %2 = load %struct.array_descriptor** %desc.addr, align 8
  %next = getelementptr inbounds %struct.array_descriptor* %2, i32 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next, align 8
  %3 = load %struct.array_descriptor** %desc.addr, align 8
  %4 = load %struct.array_table** %table.addr, align 8
  %head1 = getelementptr inbounds %struct.array_table* %4, i32 0, i32 0
  store %struct.array_descriptor* %3, %struct.array_descriptor** %head1, align 8
  ret void
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) #2

; Function Attrs: nounwind uwtable
define i64 @array_allocate_float(%struct.array_table* %table, i64 %size, float* %populate) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %size.addr = alloca i64, align 8
  %populate.addr = alloca float*, align 8
  %array_id = alloca i64, align 8
  %new_desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  store float* %populate, float** %populate.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @create_unique_id()
  store i64 %call, i64* %array_id, align 8
  %1 = load i64* %array_id, align 8
  %2 = load i64* %size.addr, align 8
  %call1 = call %struct.array_descriptor* @new_array_descriptor(i64 %1, i64 %2, i64 1, i64 0)
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %new_desc, align 8
  %3 = load %struct.array_table** %table.addr, align 8
  %4 = load %struct.array_descriptor** %new_desc, align 8
  call void @insert_descriptor(%struct.array_table* %3, %struct.array_descriptor* %4)
  %5 = load %struct.array_descriptor** %new_desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %5, i32 0, i32 3
  %6 = load i8** %array_ptr, align 8
  %7 = load float** %populate.addr, align 8
  %8 = bitcast float* %7 to i8*
  %9 = load i64* %size.addr, align 8
  %mul = mul i64 %9, 4
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %8, i64 %mul, i32 1, i1 false)
  %10 = load i64* %array_id, align 8
  store i64 %10, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %11 = load i64* %retval
  ret i64 %11
}

; Function Attrs: nounwind uwtable
define i64 @array_allocate_string(%struct.array_table* %table, i64 %size, i64* %populate) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %size.addr = alloca i64, align 8
  %populate.addr = alloca i64*, align 8
  %array_id = alloca i64, align 8
  %new_desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  store i64* %populate, i64** %populate.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @create_unique_id()
  store i64 %call, i64* %array_id, align 8
  %1 = load i64* %array_id, align 8
  %2 = load i64* %size.addr, align 8
  %call1 = call %struct.array_descriptor* @new_array_descriptor(i64 %1, i64 %2, i64 4, i64 0)
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %new_desc, align 8
  %3 = load %struct.array_table** %table.addr, align 8
  %4 = load %struct.array_descriptor** %new_desc, align 8
  call void @insert_descriptor(%struct.array_table* %3, %struct.array_descriptor* %4)
  %5 = load %struct.array_descriptor** %new_desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %5, i32 0, i32 3
  %6 = load i8** %array_ptr, align 8
  %7 = load i64** %populate.addr, align 8
  %8 = bitcast i64* %7 to i8*
  %9 = load i64* %size.addr, align 8
  %mul = mul i64 %9, 8
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %8, i64 %mul, i32 1, i1 false)
  %10 = load i64* %array_id, align 8
  store i64 %10, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %11 = load i64* %retval
  ret i64 %11
}

; Function Attrs: nounwind uwtable
define i64 @array_allocate_char(%struct.array_table* %table, i64 %size, i8* %populate) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %size.addr = alloca i64, align 8
  %populate.addr = alloca i8*, align 8
  %array_id = alloca i64, align 8
  %new_desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  store i8* %populate, i8** %populate.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @create_unique_id()
  store i64 %call, i64* %array_id, align 8
  %1 = load i64* %array_id, align 8
  %2 = load i64* %size.addr, align 8
  %call1 = call %struct.array_descriptor* @new_array_descriptor(i64 %1, i64 %2, i64 3, i64 0)
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %new_desc, align 8
  %3 = load %struct.array_table** %table.addr, align 8
  %4 = load %struct.array_descriptor** %new_desc, align 8
  call void @insert_descriptor(%struct.array_table* %3, %struct.array_descriptor* %4)
  %5 = load %struct.array_descriptor** %new_desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %5, i32 0, i32 3
  %6 = load i8** %array_ptr, align 8
  %7 = load i8** %populate.addr, align 8
  %8 = load i64* %size.addr, align 8
  %mul = mul i64 %8, 1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 %mul, i32 1, i1 false)
  %9 = load i64* %array_id, align 8
  store i64 %9, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %10 = load i64* %retval
  ret i64 %10
}

; Function Attrs: nounwind uwtable
define i64 @array_allocate_bool(%struct.array_table* %table, i64 %size, i8* %populate) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %size.addr = alloca i64, align 8
  %populate.addr = alloca i8*, align 8
  %array_id = alloca i64, align 8
  %new_desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %size, i64* %size.addr, align 8
  store i8* %populate, i8** %populate.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @create_unique_id()
  store i64 %call, i64* %array_id, align 8
  %1 = load i64* %array_id, align 8
  %2 = load i64* %size.addr, align 8
  %call1 = call %struct.array_descriptor* @new_array_descriptor(i64 %1, i64 %2, i64 2, i64 0)
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %new_desc, align 8
  %3 = load %struct.array_table** %table.addr, align 8
  %4 = load %struct.array_descriptor** %new_desc, align 8
  call void @insert_descriptor(%struct.array_table* %3, %struct.array_descriptor* %4)
  %5 = load %struct.array_descriptor** %new_desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %5, i32 0, i32 3
  %6 = load i8** %array_ptr, align 8
  %7 = load i8** %populate.addr, align 8
  %8 = load i64* %size.addr, align 8
  %mul = mul i64 %8, 1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 %mul, i32 1, i1 false)
  %9 = load i64* %array_id, align 8
  store i64 %9, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %10 = load i64* %retval
  ret i64 %10
}

; Function Attrs: nounwind uwtable
define void @array_add_reference(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %ref_count = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 4
  %5 = load i64* %ref_count, align 8
  %inc = add i64 %5, 1
  store i64 %inc, i64* %ref_count, align 8
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define internal %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %table, i64 %id) #0 {
entry:
  %retval = alloca %struct.array_descriptor*, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %id.addr = alloca i64, align 8
  %current = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %id, i64* %id.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.array_table* %0, i32 0, i32 0
  %1 = load %struct.array_descriptor** %head, align 8
  store %struct.array_descriptor* %1, %struct.array_descriptor** %current, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %2 = load %struct.array_descriptor** %current, align 8
  %tobool = icmp ne %struct.array_descriptor* %2, null
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %3 = load %struct.array_descriptor** %current, align 8
  %array_id = getelementptr inbounds %struct.array_descriptor* %3, i32 0, i32 0
  %4 = load i64* %array_id, align 8
  %5 = load i64* %id.addr, align 8
  %cmp = icmp eq i64 %4, %5
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  %6 = load %struct.array_descriptor** %current, align 8
  store %struct.array_descriptor* %6, %struct.array_descriptor** %retval
  br label %return

if.end:                                           ; preds = %while.body
  %7 = load %struct.array_descriptor** %current, align 8
  %next = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 5
  %8 = load %struct.array_descriptor** %next, align 8
  store %struct.array_descriptor* %8, %struct.array_descriptor** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store %struct.array_descriptor* null, %struct.array_descriptor** %retval
  br label %return

return:                                           ; preds = %while.end, %if.then
  %9 = load %struct.array_descriptor** %retval
  ret %struct.array_descriptor* %9
}

; Function Attrs: nounwind uwtable
define void @array_rm_reference(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %if.end6

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %if.end6

if.end3:                                          ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %ref_count = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 4
  %5 = load i64* %ref_count, align 8
  %dec = add i64 %5, -1
  store i64 %dec, i64* %ref_count, align 8
  %6 = load %struct.array_descriptor** %desc, align 8
  %ref_count4 = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 4
  %7 = load i64* %ref_count4, align 8
  %cmp = icmp eq i64 %7, 0
  br i1 %cmp, label %if.then5, label %if.end6

if.then5:                                         ; preds = %if.end3
  %8 = load %struct.array_table** %table.addr, align 8
  %9 = load i64* %arrid.addr, align 8
  call void @array_deallocate(%struct.array_table* %8, i64 %9)
  br label %if.end6

if.end6:                                          ; preds = %if.then, %if.then2, %if.then5, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_deallocate(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %current = alloca %struct.array_descriptor*, align 8
  %previous = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %while.end

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.array_table* %1, i32 0, i32 0
  %2 = load %struct.array_descriptor** %head, align 8
  store %struct.array_descriptor* %2, %struct.array_descriptor** %current, align 8
  store %struct.array_descriptor* null, %struct.array_descriptor** %previous, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end9, %if.end
  %3 = load %struct.array_descriptor** %current, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %4 = load %struct.array_descriptor** %current, align 8
  %array_id = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 0
  %5 = load i64* %array_id, align 8
  %6 = load i64* %arrid.addr, align 8
  %cmp = icmp eq i64 %5, %6
  br i1 %cmp, label %if.then2, label %if.end9

if.then2:                                         ; preds = %while.body
  %7 = load %struct.array_descriptor** %previous, align 8
  %cmp3 = icmp ne %struct.array_descriptor* %7, null
  br i1 %cmp3, label %if.then4, label %if.else

if.then4:                                         ; preds = %if.then2
  %8 = load %struct.array_descriptor** %current, align 8
  %next = getelementptr inbounds %struct.array_descriptor* %8, i32 0, i32 5
  %9 = load %struct.array_descriptor** %next, align 8
  %10 = load %struct.array_descriptor** %previous, align 8
  %next5 = getelementptr inbounds %struct.array_descriptor* %10, i32 0, i32 5
  store %struct.array_descriptor* %9, %struct.array_descriptor** %next5, align 8
  br label %if.end8

if.else:                                          ; preds = %if.then2
  %11 = load %struct.array_descriptor** %current, align 8
  %next6 = getelementptr inbounds %struct.array_descriptor* %11, i32 0, i32 5
  %12 = load %struct.array_descriptor** %next6, align 8
  %13 = load %struct.array_table** %table.addr, align 8
  %head7 = getelementptr inbounds %struct.array_table* %13, i32 0, i32 0
  store %struct.array_descriptor* %12, %struct.array_descriptor** %head7, align 8
  br label %if.end8

if.end8:                                          ; preds = %if.else, %if.then4
  %14 = load %struct.array_descriptor** %current, align 8
  call void @array_descriptor_deallocate(%struct.array_descriptor* %14)
  br label %while.end

if.end9:                                          ; preds = %while.body
  %15 = load %struct.array_descriptor** %current, align 8
  store %struct.array_descriptor* %15, %struct.array_descriptor** %previous, align 8
  %16 = load %struct.array_descriptor** %current, align 8
  %next10 = getelementptr inbounds %struct.array_descriptor* %16, i32 0, i32 5
  %17 = load %struct.array_descriptor** %next10, align 8
  store %struct.array_descriptor* %17, %struct.array_descriptor** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %if.then, %if.end8, %while.cond
  ret void
}

; Function Attrs: nounwind uwtable
define i64 @array_size(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 1
  %5 = load i64* %array_size, align 8
  store i64 %5, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %6 = load i64* %retval
  ret i64 %6
}

; Function Attrs: nounwind uwtable
define i64 @array_ref_count(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %ref_count = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 4
  %5 = load i64* %ref_count, align 8
  store i64 %5, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %6 = load i64* %retval
  ret i64 %6
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @array_descriptor_deallocate(%struct.array_descriptor* %desc) #1 {
entry:
  %desc.addr = alloca %struct.array_descriptor*, align 8
  store %struct.array_descriptor* %desc, %struct.array_descriptor** %desc.addr, align 8
  %0 = load %struct.array_descriptor** %desc.addr, align 8
  %tobool = icmp ne %struct.array_descriptor* %0, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %1, i32 0, i32 3
  %2 = load i8** %array_ptr, align 8
  call void @free(i8* %2) #2
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %3 = load %struct.array_descriptor** %desc.addr, align 8
  %4 = bitcast %struct.array_descriptor* %3 to i8*
  call void @free(i8* %4) #2
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_int(%struct.array_table* %table, i64 %arrid, i32 %value, i64 %pos) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i32, align 4
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i32 %value, i32* %value.addr, align 4
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 0
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %8 = bitcast i32* %value.addr to i8*
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %7, i8* %8)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @array_insert_value(%struct.array_descriptor* %desc, i64 %pos, i8* %val) #0 {
entry:
  %desc.addr = alloca %struct.array_descriptor*, align 8
  %pos.addr = alloca i64, align 8
  %val.addr = alloca i8*, align 8
  %src = alloca i8*, align 8
  %dst = alloca i8*, align 8
  %num = alloca i64, align 8
  store %struct.array_descriptor* %desc, %struct.array_descriptor** %desc.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  store i8* %val, i8** %val.addr, align 8
  %0 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %0, i32 0, i32 3
  %1 = load i8** %array_ptr, align 8
  %2 = load %struct.array_descriptor** %desc.addr, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %2, i32 0, i32 1
  %3 = load i64* %array_size, align 8
  %add = add i64 %3, 1
  %4 = load %struct.array_descriptor** %desc.addr, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %call = call i64 @num_bytes(i64 %5)
  %mul = mul i64 %add, %call
  %call1 = call i8* @realloc(i8* %1, i64 %mul) #2
  %6 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr2 = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 3
  store i8* %call1, i8** %array_ptr2, align 8
  %7 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr3 = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 3
  %8 = load i8** %array_ptr3, align 8
  %tobool = icmp ne i8* %8, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %9 = load %struct._IO_FILE** @stderr, align 8
  %call4 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %9, i8* getelementptr inbounds ([51 x i8]* @.str2, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %10 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr5 = getelementptr inbounds %struct.array_descriptor* %10, i32 0, i32 3
  %11 = load i8** %array_ptr5, align 8
  %12 = load %struct.array_descriptor** %desc.addr, align 8
  %type6 = getelementptr inbounds %struct.array_descriptor* %12, i32 0, i32 2
  %13 = load i64* %type6, align 8
  %call7 = call i64 @num_bytes(i64 %13)
  %14 = load i64* %pos.addr, align 8
  %mul8 = mul i64 %call7, %14
  %add.ptr = getelementptr i8* %11, i64 %mul8
  store i8* %add.ptr, i8** %src, align 8
  %15 = load i8** %src, align 8
  %16 = load %struct.array_descriptor** %desc.addr, align 8
  %type9 = getelementptr inbounds %struct.array_descriptor* %16, i32 0, i32 2
  %17 = load i64* %type9, align 8
  %call10 = call i64 @num_bytes(i64 %17)
  %add.ptr11 = getelementptr i8* %15, i64 %call10
  store i8* %add.ptr11, i8** %dst, align 8
  %18 = load %struct.array_descriptor** %desc.addr, align 8
  %type12 = getelementptr inbounds %struct.array_descriptor* %18, i32 0, i32 2
  %19 = load i64* %type12, align 8
  %call13 = call i64 @num_bytes(i64 %19)
  %20 = load %struct.array_descriptor** %desc.addr, align 8
  %array_size14 = getelementptr inbounds %struct.array_descriptor* %20, i32 0, i32 1
  %21 = load i64* %array_size14, align 8
  %22 = load i64* %pos.addr, align 8
  %sub = sub i64 %21, %22
  %mul15 = mul i64 %call13, %sub
  store i64 %mul15, i64* %num, align 8
  %23 = load i8** %dst, align 8
  %24 = load i8** %src, align 8
  %25 = load i64* %num, align 8
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %23, i8* %24, i64 %25, i32 1, i1 false)
  %26 = load i8** %src, align 8
  %27 = load i8** %val.addr, align 8
  %28 = load %struct.array_descriptor** %desc.addr, align 8
  %type16 = getelementptr inbounds %struct.array_descriptor* %28, i32 0, i32 2
  %29 = load i64* %type16, align 8
  %call17 = call i64 @num_bytes(i64 %29)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %26, i8* %27, i64 %call17, i32 1, i1 false)
  %30 = load %struct.array_descriptor** %desc.addr, align 8
  %array_size18 = getelementptr inbounds %struct.array_descriptor* %30, i32 0, i32 1
  %31 = load i64* %array_size18, align 8
  %inc = add i64 %31, 1
  store i64 %inc, i64* %array_size18, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_bool(%struct.array_table* %table, i64 %arrid, i1 zeroext %value, i64 %pos) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 2
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %7, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_float(%struct.array_table* %table, i64 %arrid, float %value, i64 %pos) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca float, align 4
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store float %value, float* %value.addr, align 4
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 1
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %8 = bitcast float* %value.addr to i8*
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %7, i8* %8)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_char(%struct.array_table* %table, i64 %arrid, i8 signext %value, i64 %pos) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i8 %value, i8* %value.addr, align 1
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 3
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %7, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_string(%struct.array_table* %table, i64 %arrid, i64 %value, i64 %pos) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %value, i64* %value.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 4
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %8 = bitcast i64* %value.addr to i8*
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %7, i8* %8)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @array_get_int(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 0
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = bitcast i8* %call4 to i32*
  %9 = load i32* %8, align 4
  store i32 %9, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i32* %retval
  ret i32 %10
}

; Function Attrs: nounwind uwtable
define internal i8* @array_get_value(%struct.array_descriptor* %desc, i64 %pos) #0 {
entry:
  %desc.addr = alloca %struct.array_descriptor*, align 8
  %pos.addr = alloca i64, align 8
  store %struct.array_descriptor* %desc, %struct.array_descriptor** %desc.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %0, i32 0, i32 3
  %1 = load i8** %array_ptr, align 8
  %2 = load i64* %pos.addr, align 8
  %3 = load %struct.array_descriptor** %desc.addr, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %3, i32 0, i32 2
  %4 = load i64* %type, align 8
  %call = call i64 @num_bytes(i64 %4)
  %mul = mul i64 %2, %call
  %add.ptr = getelementptr i8* %1, i64 %mul
  ret i8* %add.ptr
}

; Function Attrs: nounwind uwtable
define float @array_get_float(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 1
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = bitcast i8* %call4 to float*
  %9 = load float* %8, align 4
  store float %9, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load float* %retval
  ret float %10
}

; Function Attrs: nounwind uwtable
define zeroext i1 @array_get_bool(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 2
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = load i8* %call4, align 1
  %tobool5 = trunc i8 %8 to i1
  store i1 %tobool5, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i1* %retval
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define signext i8 @array_get_char(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 3
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = load i8* %call4, align 1
  store i8 %8, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i8* %retval
  ret i8 %9
}

; Function Attrs: nounwind uwtable
define i64 @array_get_string(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 4
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = bitcast i8* %call4 to i64*
  %9 = load i64* %8, align 8
  store i64 %9, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i64* %retval
  ret i64 %10
}

; Function Attrs: nounwind uwtable
define void @array_clear(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 3
  %5 = load i8** %array_ptr, align 8
  call void @free(i8* %5) #2
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  store i64 0, i64* %array_size, align 8
  %7 = load %struct.array_descriptor** %desc, align 8
  %array_ptr4 = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 3
  store i8* null, i8** %array_ptr4, align 8
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind
declare void @free(i8*) #3

; Function Attrs: nounwind uwtable
define void @array_remove(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  call void @array_remove_value(%struct.array_descriptor* %4, i64 %5)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @array_remove_value(%struct.array_descriptor* %desc, i64 %pos) #0 {
entry:
  %desc.addr = alloca %struct.array_descriptor*, align 8
  %pos.addr = alloca i64, align 8
  %dst = alloca i8*, align 8
  %src = alloca i8*, align 8
  %num = alloca i64, align 8
  store %struct.array_descriptor* %desc, %struct.array_descriptor** %desc.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %0, i32 0, i32 3
  %1 = load i8** %array_ptr, align 8
  %2 = load i64* %pos.addr, align 8
  %3 = load %struct.array_descriptor** %desc.addr, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %3, i32 0, i32 2
  %4 = load i64* %type, align 8
  %call = call i64 @num_bytes(i64 %4)
  %mul = mul i64 %2, %call
  %add.ptr = getelementptr i8* %1, i64 %mul
  store i8* %add.ptr, i8** %dst, align 8
  %5 = load i8** %dst, align 8
  %6 = load %struct.array_descriptor** %desc.addr, align 8
  %type1 = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 2
  %7 = load i64* %type1, align 8
  %call2 = call i64 @num_bytes(i64 %7)
  %add.ptr3 = getelementptr i8* %5, i64 %call2
  store i8* %add.ptr3, i8** %src, align 8
  %8 = load %struct.array_descriptor** %desc.addr, align 8
  %type4 = getelementptr inbounds %struct.array_descriptor* %8, i32 0, i32 2
  %9 = load i64* %type4, align 8
  %call5 = call i64 @num_bytes(i64 %9)
  %10 = load %struct.array_descriptor** %desc.addr, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %10, i32 0, i32 1
  %11 = load i64* %array_size, align 8
  %12 = load i64* %pos.addr, align 8
  %sub = sub i64 %11, %12
  %sub6 = sub i64 %sub, 1
  %mul7 = mul i64 %call5, %sub6
  store i64 %mul7, i64* %num, align 8
  %13 = load i8** %dst, align 8
  %14 = load i8** %src, align 8
  %15 = load i64* %num, align 8
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %13, i8* %14, i64 %15, i32 1, i1 false)
  %16 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr8 = getelementptr inbounds %struct.array_descriptor* %16, i32 0, i32 3
  %17 = load i8** %array_ptr8, align 8
  %18 = load %struct.array_descriptor** %desc.addr, align 8
  %type9 = getelementptr inbounds %struct.array_descriptor* %18, i32 0, i32 2
  %19 = load i64* %type9, align 8
  %call10 = call i64 @num_bytes(i64 %19)
  %20 = load %struct.array_descriptor** %desc.addr, align 8
  %array_size11 = getelementptr inbounds %struct.array_descriptor* %20, i32 0, i32 1
  %21 = load i64* %array_size11, align 8
  %sub12 = sub i64 %21, 1
  %mul13 = mul i64 %call10, %sub12
  %call14 = call i8* @realloc(i8* %17, i64 %mul13) #2
  %22 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr15 = getelementptr inbounds %struct.array_descriptor* %22, i32 0, i32 3
  store i8* %call14, i8** %array_ptr15, align 8
  %23 = load %struct.array_descriptor** %desc.addr, align 8
  %array_ptr16 = getelementptr inbounds %struct.array_descriptor* %23, i32 0, i32 3
  %24 = load i8** %array_ptr16, align 8
  %tobool = icmp ne i8* %24, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %25 = load %struct._IO_FILE** @stderr, align 8
  %call17 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %25, i8* getelementptr inbounds ([51 x i8]* @.str1, i32 0, i32 0))
  call void @exit(i32 1) #6
  unreachable

if.end:                                           ; preds = %entry
  %26 = load %struct.array_descriptor** %desc.addr, align 8
  %array_size18 = getelementptr inbounds %struct.array_descriptor* %26, i32 0, i32 1
  %27 = load i64* %array_size18, align 8
  %dec = add i64 %27, -1
  store i64 %dec, i64* %array_size18, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @array_remove_int(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %value = alloca i32, align 4
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 0
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = bitcast i8* %call4 to i32*
  %9 = load i32* %8, align 4
  store i32 %9, i32* %value, align 4
  %10 = load %struct.array_descriptor** %desc, align 8
  %11 = load i64* %pos.addr, align 8
  call void @array_remove_value(%struct.array_descriptor* %10, i64 %11)
  %12 = load i32* %value, align 4
  store i32 %12, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %13 = load i32* %retval
  ret i32 %13
}

; Function Attrs: nounwind uwtable
define float @array_remove_float(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %value = alloca float, align 4
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 1
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = bitcast i8* %call4 to float*
  %9 = load float* %8, align 4
  store float %9, float* %value, align 4
  %10 = load %struct.array_descriptor** %desc, align 8
  %11 = load i64* %pos.addr, align 8
  call void @array_remove_value(%struct.array_descriptor* %10, i64 %11)
  %12 = load float* %value, align 4
  store float %12, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %13 = load float* %retval
  ret float %13
}

; Function Attrs: nounwind uwtable
define zeroext i1 @array_remove_bool(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %value = alloca i8, align 1
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 2
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = load i8* %call4, align 1
  %tobool5 = trunc i8 %8 to i1
  %frombool = zext i1 %tobool5 to i8
  store i8 %frombool, i8* %value, align 1
  %9 = load %struct.array_descriptor** %desc, align 8
  %10 = load i64* %pos.addr, align 8
  call void @array_remove_value(%struct.array_descriptor* %9, i64 %10)
  %11 = load i8* %value, align 1
  %tobool6 = trunc i8 %11 to i1
  store i1 %tobool6, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %12 = load i1* %retval
  ret i1 %12
}

; Function Attrs: nounwind uwtable
define signext i8 @array_remove_char(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %value = alloca i8, align 1
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 3
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = load i8* %call4, align 1
  store i8 %8, i8* %value, align 1
  %9 = load %struct.array_descriptor** %desc, align 8
  %10 = load i64* %pos.addr, align 8
  call void @array_remove_value(%struct.array_descriptor* %9, i64 %10)
  %11 = load i8* %value, align 1
  store i8 %11, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %12 = load i8* %retval
  ret i8 %12
}

; Function Attrs: nounwind uwtable
define i64 @array_remove_string(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %value = alloca i64, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 4
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load i64* %pos.addr, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %6, i64 %7)
  %8 = bitcast i8* %call4 to i64*
  %9 = load i64* %8, align 8
  store i64 %9, i64* %value, align 8
  %10 = load %struct.array_descriptor** %desc, align 8
  %11 = load i64* %pos.addr, align 8
  call void @array_remove_value(%struct.array_descriptor* %10, i64 %11)
  %12 = load i64* %value, align 8
  store i64 %12, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %13 = load i64* %retval
  ret i64 %13
}

; Function Attrs: nounwind uwtable
define i32 @array_pop_int(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %last_position = alloca i64, align 8
  %value = alloca i32, align 4
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 0
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  %7 = load i64* %array_size, align 8
  %sub = sub i64 %7, 1
  store i64 %sub, i64* %last_position, align 8
  %8 = load %struct.array_descriptor** %desc, align 8
  %9 = load i64* %last_position, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %8, i64 %9)
  %10 = bitcast i8* %call4 to i32*
  %11 = load i32* %10, align 4
  store i32 %11, i32* %value, align 4
  %12 = load %struct.array_descriptor** %desc, align 8
  %13 = load i64* %last_position, align 8
  call void @array_remove_value(%struct.array_descriptor* %12, i64 %13)
  %14 = load i32* %value, align 4
  store i32 %14, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %15 = load i32* %retval
  ret i32 %15
}

; Function Attrs: nounwind uwtable
define float @array_pop_float(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %last_position = alloca i64, align 8
  %value = alloca float, align 4
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 1
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  %7 = load i64* %array_size, align 8
  %sub = sub i64 %7, 1
  store i64 %sub, i64* %last_position, align 8
  %8 = load %struct.array_descriptor** %desc, align 8
  %9 = load i64* %last_position, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %8, i64 %9)
  %10 = bitcast i8* %call4 to float*
  %11 = load float* %10, align 4
  store float %11, float* %value, align 4
  %12 = load %struct.array_descriptor** %desc, align 8
  %13 = load i64* %last_position, align 8
  call void @array_remove_value(%struct.array_descriptor* %12, i64 %13)
  %14 = load float* %value, align 4
  store float %14, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %15 = load float* %retval
  ret float %15
}

; Function Attrs: nounwind uwtable
define zeroext i1 @array_pop_bool(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %last_position = alloca i64, align 8
  %value = alloca i8, align 1
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 2
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  %7 = load i64* %array_size, align 8
  %sub = sub i64 %7, 1
  store i64 %sub, i64* %last_position, align 8
  %8 = load %struct.array_descriptor** %desc, align 8
  %9 = load i64* %last_position, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %8, i64 %9)
  %10 = load i8* %call4, align 1
  %tobool5 = trunc i8 %10 to i1
  %frombool = zext i1 %tobool5 to i8
  store i8 %frombool, i8* %value, align 1
  %11 = load %struct.array_descriptor** %desc, align 8
  %12 = load i64* %last_position, align 8
  call void @array_remove_value(%struct.array_descriptor* %11, i64 %12)
  %13 = load i8* %value, align 1
  %tobool6 = trunc i8 %13 to i1
  store i1 %tobool6, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %14 = load i1* %retval
  ret i1 %14
}

; Function Attrs: nounwind uwtable
define signext i8 @array_pop_char(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %last_position = alloca i64, align 8
  %value = alloca i8, align 1
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 3
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  %7 = load i64* %array_size, align 8
  %sub = sub i64 %7, 1
  store i64 %sub, i64* %last_position, align 8
  %8 = load %struct.array_descriptor** %desc, align 8
  %9 = load i64* %last_position, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %8, i64 %9)
  %10 = load i8* %call4, align 1
  store i8 %10, i8* %value, align 1
  %11 = load %struct.array_descriptor** %desc, align 8
  %12 = load i64* %last_position, align 8
  call void @array_remove_value(%struct.array_descriptor* %11, i64 %12)
  %13 = load i8* %value, align 1
  store i8 %13, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %14 = load i8* %retval
  ret i8 %14
}

; Function Attrs: nounwind uwtable
define i64 @array_pop_string(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  %last_position = alloca i64, align 8
  %value = alloca i64, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 4
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %6, i32 0, i32 1
  %7 = load i64* %array_size, align 8
  %sub = sub i64 %7, 1
  store i64 %sub, i64* %last_position, align 8
  %8 = load %struct.array_descriptor** %desc, align 8
  %9 = load i64* %last_position, align 8
  %call4 = call i8* @array_get_value(%struct.array_descriptor* %8, i64 %9)
  %10 = bitcast i8* %call4 to i64*
  %11 = load i64* %10, align 8
  store i64 %11, i64* %value, align 8
  %12 = load %struct.array_descriptor** %desc, align 8
  %13 = load i64* %last_position, align 8
  call void @array_remove_value(%struct.array_descriptor* %12, i64 %13)
  %14 = load i64* %value, align 8
  store i64 %14, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %15 = load i64* %retval
  ret i64 %15
}

; Function Attrs: nounwind uwtable
define void @array_push_int(%struct.array_table* %table, i64 %arrid, i32 %value) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i32, align 4
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i32 %value, i32* %value.addr, align 4
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 0
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 1
  %8 = load i64* %array_size, align 8
  %9 = bitcast i32* %value.addr to i8*
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %8, i8* %9)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_float(%struct.array_table* %table, i64 %arrid, float %value) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca float, align 4
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store float %value, float* %value.addr, align 4
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 1
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 1
  %8 = load i64* %array_size, align 8
  %9 = bitcast float* %value.addr to i8*
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %8, i8* %9)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_bool(%struct.array_table* %table, i64 %arrid, i1 zeroext %value) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 2
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 1
  %8 = load i64* %array_size, align 8
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %8, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_char(%struct.array_table* %table, i64 %arrid, i8 signext %value) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i8 %value, i8* %value.addr, align 1
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 3
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 1
  %8 = load i64* %array_size, align 8
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %8, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_string(%struct.array_table* %table, i64 %arrid, i64 %value) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  %arrid.addr = alloca i64, align 8
  %value.addr = alloca i64, align 8
  %desc = alloca %struct.array_descriptor*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  store i64 %arrid, i64* %arrid.addr, align 8
  store i64 %value, i64* %value.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %tobool = icmp ne %struct.array_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.array_table** %table.addr, align 8
  %2 = load i64* %arrid.addr, align 8
  %call = call %struct.array_descriptor* @find_array_descriptor(%struct.array_table* %1, i64 %2)
  store %struct.array_descriptor* %call, %struct.array_descriptor** %desc, align 8
  %3 = load %struct.array_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.array_descriptor* %3, null
  br i1 %tobool1, label %lor.lhs.false, label %if.then2

lor.lhs.false:                                    ; preds = %if.end
  %4 = load %struct.array_descriptor** %desc, align 8
  %type = getelementptr inbounds %struct.array_descriptor* %4, i32 0, i32 2
  %5 = load i64* %type, align 8
  %cmp = icmp ne i64 %5, 4
  br i1 %cmp, label %if.then2, label %if.end3

if.then2:                                         ; preds = %lor.lhs.false, %if.end
  br label %return

if.end3:                                          ; preds = %lor.lhs.false
  %6 = load %struct.array_descriptor** %desc, align 8
  %7 = load %struct.array_descriptor** %desc, align 8
  %array_size = getelementptr inbounds %struct.array_descriptor* %7, i32 0, i32 1
  %8 = load i64* %array_size, align 8
  %9 = bitcast i64* %value.addr to i8*
  call void @array_insert_value(%struct.array_descriptor* %6, i64 %8, i8* %9)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define %struct.array_table* @create_array_table() #0 {
entry:
  %table = alloca %struct.array_table*, align 8
  %call = call noalias i8* @malloc(i64 8) #2
  %0 = bitcast i8* %call to %struct.array_table*
  store %struct.array_table* %0, %struct.array_table** %table, align 8
  %1 = load %struct.array_table** %table, align 8
  %tobool = icmp ne %struct.array_table* %1, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE** @stderr, align 8
  %call1 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([51 x i8]* @.str, i32 0, i32 0))
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %3 = load %struct.array_table** %table, align 8
  %head = getelementptr inbounds %struct.array_table* %3, i32 0, i32 0
  store %struct.array_descriptor* null, %struct.array_descriptor** %head, align 8
  %4 = load %struct.array_table** %table, align 8
  ret %struct.array_table* %4
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #3

declare i32 @fprintf(%struct._IO_FILE*, i8*, ...) #4

; Function Attrs: nounwind uwtable
define void @delete_array_table(%struct.array_table* %table) #0 {
entry:
  %table.addr = alloca %struct.array_table*, align 8
  store %struct.array_table* %table, %struct.array_table** %table.addr, align 8
  %0 = load %struct.array_table** %table.addr, align 8
  %1 = bitcast %struct.array_table* %0 to i8*
  call void @free(i8* %1) #2
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define internal i64 @num_bytes(i64 %type) #1 {
entry:
  %type.addr = alloca i64, align 8
  store i64 %type, i64* %type.addr, align 8
  %0 = load i64* %type.addr, align 8
  %arrayidx = getelementptr inbounds [5 x i64]* @bytes_per_type, i32 0, i64 %0
  %1 = load i64* %arrayidx, align 8
  ret i64 %1
}

; Function Attrs: nounwind
declare void @llvm.memmove.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) #2

; Function Attrs: nounwind
declare i8* @realloc(i8*, i64) #3

; Function Attrs: noreturn nounwind
declare void @exit(i32) #5

; Function Attrs: nounwind uwtable
define internal i64 @create_unique_id() #0 {
entry:
  %0 = load i64* @array_counter, align 8
  %inc = add i64 %0, 1
  store i64 %inc, i64* @array_counter, align 8
  ret i64 %0
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { inlinehint nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }
attributes #3 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { noreturn nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { noreturn nounwind }
