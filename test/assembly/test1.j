.class public test1
.super java/lang/Object
.field public static a I
.field public static b I
.field public static c I
.field public static u I
.field public static d [I
.field public static e [F
.field public static g F
.field public static h F
.field public static x F
.field public static k [[F
.field public static l [[I
.method public static sort([I)V
.limit locals 50
.limit stack 50
    ldc 0
    istore 1
    iload  1
    putstatic test1/c I
    return
.end method
.method public static addition(II)I
.limit locals 50
.limit stack 50
    iload  0
    iload  1
    iadd
    ireturn
.end method
.method public static ggyy(FF)F
.limit locals 50
.limit stack 50
    fload  0
    fload  1
    fadd
    freturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test1/a I
    ldc 0
    putstatic test1/b I
    ldc 0
    putstatic test1/c I
    ldc 0
    putstatic test1/u I
    ldc 10
    multianewarray [I 1
    putstatic test1/d [I
    ldc 10
    multianewarray [F 1
    putstatic test1/e [F
    ldc 0.0
    putstatic test1/g F
    ldc 0.0
    putstatic test1/h F
    ldc 0.0
    putstatic test1/x F
    ldc 35
    ldc 35
    multianewarray [[F 2
    putstatic test1/k [[F
    ldc 35
    ldc 35
    multianewarray [[I 2
    putstatic test1/l [[I
    ldc 8
    ldc 8
    invokestatic test1/addition(II)I
    putstatic test1/c I
    getstatic test1/c I
    invokestatic io/writelnI(I)V
    ldc 8
    ineg
    ldc 8
    ineg
    invokestatic test1/addition(II)I
    putstatic test1/c I
    getstatic test1/c I
    invokestatic io/writelnI(I)V
    ldc 3.300000
    ldc 5.500000
    invokestatic test1/ggyy(FF)F
    putstatic test1/x F
    getstatic test1/x F
    invokestatic io/writelnR(F)V
    ldc 0
    putstatic test1/b I
    getstatic test1/b I
    getstatic test1/a I
    if_icmpgt L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifne L3
    ldc 222
    putstatic test1/a I
    goto L4
L3:
    ldc 111
    putstatic test1/a I
    goto L4
L4:
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/b I
    getstatic test1/a I
    if_icmplt L5
    ldc 0
    goto L6
L5:
    ldc 1
L6:
    ifne L7
    ldc 222
    putstatic test1/a I
    goto L8
L7:
    ldc 111
    putstatic test1/a I
    goto L8
L8:
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/b I
    getstatic test1/a I
    if_icmpeq L9
    ldc 0
    goto L10
L9:
    ldc 1
L10:
    ifne L11
    ldc 222
    putstatic test1/a I
    goto L12
L11:
    ldc 111
    putstatic test1/a I
    goto L12
L12:
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/b I
    getstatic test1/a I
    if_icmpge L13
    ldc 0
    goto L14
L13:
    ldc 1
L14:
    ifne L15
    ldc 222
    putstatic test1/a I
    goto L16
L15:
    ldc 111
    putstatic test1/a I
    goto L16
L16:
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/b I
    getstatic test1/a I
    if_icmple L17
    ldc 0
    goto L18
L17:
    ldc 1
L18:
    ifne L19
    ldc 222
    putstatic test1/a I
    goto L20
L19:
    ldc 111
    putstatic test1/a I
    goto L20
L20:
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/b I
    ldc 0
    if_icmpne L21
    ldc 0
    goto L22
L21:
    ldc 1
L22:
    ifne L23
    ldc 222
    putstatic test1/a I
    goto L24
L23:
    ldc 111
    putstatic test1/a I
    goto L24
L24:
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    ldc 1
    putstatic test1/a I
L25:
    getstatic test1/a I
    ldc 5
    if_icmplt L26
    ldc 0
    goto L27
L26:
    ldc 1
L27:
    ifeq L28
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/a I
    ldc 1
    iadd
    putstatic test1/a I
    goto L25
L28:
    ldc 1
    putstatic test1/b I
L29:
    getstatic test1/b I
    ldc 11
    if_icmplt L30
    ldc 0
    goto L31
L30:
    ldc 1
L31:
    ifeq L32
    getstatic test1/d [I
    getstatic test1/b I
    ldc 1
    isub
    getstatic test1/b I
    getstatic test1/b I
    getstatic test1/b I
    ldc 3
    iadd
    imul
    iadd
    iastore
    getstatic test1/b I
    ldc 1
    iadd
    putstatic test1/b I
    goto L29
L32:
    getstatic test1/e [F
    ldc 3
    ldc 1
    isub
    ldc 9.990000
    fastore
    getstatic test1/k [[F
    ldc 25
    ldc 23
    isub
    aaload
    ldc 26
    ldc 23
    isub
    ldc 3.140000
    fastore
    getstatic test1/l [[I
    ldc 28
    ldc 23
    isub
    aaload
    ldc 26
    ldc 23
    isub
    ldc 88
    iastore
    getstatic test1/a I
    invokestatic io/writelnI(I)V
    getstatic test1/d [I
    ldc 5
    ldc 1
    isub
    iaload
    putstatic test1/u I
    getstatic test1/u I
    invokestatic io/writelnI(I)V
    getstatic test1/e [F
    ldc 3
    ldc 1
    isub
    faload
    putstatic test1/g F
    getstatic test1/g F
    invokestatic io/writelnR(F)V
    getstatic test1/k [[F
    ldc 25
    ldc 23
    isub
    aaload
    ldc 26
    ldc 23
    isub
    faload
    putstatic test1/g F
    getstatic test1/g F
    invokestatic io/writelnR(F)V
    getstatic test1/l [[I
    ldc 28
    ldc 23
    isub
    aaload
    ldc 26
    ldc 23
    isub
    iaload
    putstatic test1/u I
    getstatic test1/u I
    invokestatic io/writelnI(I)V
    ldc 9
    ldc 9
    iadd
    ldc 10
    isub
    putstatic test1/u I
    getstatic test1/u I
    invokestatic io/writelnI(I)V
    ldc 9
    ldc 9
    iadd
    ldc 3
    idiv
    ldc 5
    ldc 2
    imul
    iadd
    ldc 1
    isub
    getstatic test1/u I
    iadd
    putstatic test1/u I
    getstatic test1/u I
    invokestatic io/writelnI(I)V
    return
.end method
