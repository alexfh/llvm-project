// RUN: %clang_cc1 -triple bpfel -emit-llvm -debug-info-kind=constructor %s -o - | FileCheck %s

// CHECK: @_Z9__cat_op0v = alias void (), ptr @e
// CHECK: !DIImportedEntity(tag: DW_TAG_imported_declaration, name: "__cat_op0", {{.*}} entity: ![[ENTITY:[0-9]+]]
// CHECK: ![[ENTITY]] = !DISubprogram(name: "__cat_op0", linkageName: "_Z9__cat_op0v"

extern "C" void e() {}
void __attribute__((alias("e"))) __cat_op0();
void r() { __cat_op0(); }
