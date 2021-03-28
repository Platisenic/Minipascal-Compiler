.class public test_nestedStmt
.super java/lang/Object
.field public static a I
.field public static b I
.field public static d I
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test_nestedStmt/a I
    ldc 0
    putstatic test_nestedStmt/b I
    ldc 0
    putstatic test_nestedStmt/d I
    ldc 1
    putstatic test_nestedStmt/a I
    ldc 7
    putstatic test_nestedStmt/b I
    ldc 9
    putstatic test_nestedStmt/d I
    getstatic test_nestedStmt/a I
    getstatic test_nestedStmt/b I
    ldc 3
    iadd
    if_icmplt L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifne L3
    getstatic test_nestedStmt/d I
    ldc 1000
    iadd
    putstatic test_nestedStmt/d I
    goto L4
L3:
    getstatic test_nestedStmt/a I
    ldc 5
    iadd
    getstatic test_nestedStmt/b I
    ldc 2
    isub
    if_icmpgt L5
    ldc 0
    goto L6
L5:
    ldc 1
L6:
    ifne L7
    getstatic test_nestedStmt/d I
    ldc 100
    iadd
    putstatic test_nestedStmt/d I
    goto L8
L7:
L9:
    getstatic test_nestedStmt/a I
    getstatic test_nestedStmt/b I
    if_icmplt L10
    ldc 0
    goto L11
L10:
    ldc 1
L11:
    ifeq L12
L13:
    getstatic test_nestedStmt/b I
    ldc 11
    if_icmplt L14
    ldc 0
    goto L15
L14:
    ldc 1
L15:
    ifeq L16
    getstatic test_nestedStmt/b I
    ldc 2
    iadd
    putstatic test_nestedStmt/b I
    goto L13
L16:
    getstatic test_nestedStmt/a I
    ldc 10
    iadd
    putstatic test_nestedStmt/a I
    goto L9
L12:
    goto L8
L8:
    goto L4
L4:
    getstatic test_nestedStmt/a I
    invokestatic io/writelnI(I)V
    getstatic test_nestedStmt/b I
    invokestatic io/writelnI(I)V
    getstatic test_nestedStmt/d I
    invokestatic io/writelnI(I)V
    return
.end method
