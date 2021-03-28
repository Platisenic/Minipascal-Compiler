.class public fibonacci_recursive
.super java/lang/Object
.field public static a I
.method public static fa(I)I
.limit locals 50
.limit stack 50
    iload  0
    ldc 1
    if_icmpeq L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifne L3
    iload  0
    ldc 0
    if_icmpeq L5
    ldc 0
    goto L6
L5:
    ldc 1
L6:
    ifne L7
    iload  0
    ldc 1
    isub
    invokestatic fibonacci_recursive/fa(I)I
    iload  0
    ldc 2
    isub
    invokestatic fibonacci_recursive/fa(I)I
    iadd
    goto L8
L7:
    ldc 0
    goto L8
L8:
    goto L4
L3:
    ldc 1
    goto L4
L4:
    ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic fibonacci_recursive/a I
    invokestatic io/readlnI()I
    putstatic fibonacci_recursive/a I
    getstatic fibonacci_recursive/a I
    invokestatic fibonacci_recursive/fa(I)I
    invokestatic io/writelnI(I)V
    return
.end method
