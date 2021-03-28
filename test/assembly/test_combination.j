.class public test_combination
.super java/lang/Object
.field public static a I
.field public static b I
.method public static comb(II)I
.limit locals 50
.limit stack 50
    iload  0
    iload  1
    if_icmpgt L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifne L3
    ldc 1
    goto L4
L3:
    iload  0
    ldc 1
    if_icmpeq L5
    ldc 0
    goto L6
L5:
    ldc 1
L6:
    ifne L7
    iload  0
    ldc 0
    if_icmpgt L9
    ldc 0
    goto L10
L9:
    ldc 1
L10:
    ifne L11
    ldc 0
    goto L12
L11:
    iload  1
    ldc 0
    if_icmpgt L13
    ldc 0
    goto L14
L13:
    ldc 1
L14:
    ifne L15
    ldc 1
    goto L16
L15:
    iload  0
    ldc 1
    isub
    iload  1
    ldc 1
    isub
    invokestatic test_combination/comb(II)I
    iload  0
    ldc 1
    isub
    iload  1
    invokestatic test_combination/comb(II)I
    iadd
    goto L16
L16:
    goto L12
L12:
    goto L8
L7:
    ldc 1
    goto L8
L8:
    goto L4
L4:
    ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test_combination/a I
    ldc 0
    putstatic test_combination/b I
    ldc 3
    putstatic test_combination/a I
    ldc 4
    putstatic test_combination/b I
    getstatic test_combination/a I
    ldc 3
    iadd
    getstatic test_combination/b I
    ldc 2
    isub
    invokestatic test_combination/comb(II)I
    invokestatic io/writelnI(I)V
    return
.end method
