package com.byteflow.app.utils;

import android.util.Log;


/**
 * // 简单测试使用的log 日志管理 不需要去考虑 不同的编译环境不同的AS版本等问题
 *  可配置 可 打印 logcat 自动跳转
 * by iyangfeng  2022/01/22
 */
public class MyLog {

    private static String TAG = "JALOG";
    public   final static   int LOGD = 2;
    public  final static  int LOGI = 3;
    public  final static int LOGW = 4;
    public  final static int LOGE = 5;

    private String logTag;
    int printLevle;
    // LOGD 以上的信息都可以打印
    private static  int   staticPrintLevel = LOGD;


    /**
     *
     * @param logTag
     * @param level   默认为0 所有都可以打印 MyLog.LOGW 等来限制
     * @return
     */
    public static MyLog getMylog(String logTag,int level)
    {
        MyLog tmp = new MyLog(logTag,level);
        return tmp;
    }

    public MyLog(String Tag,int levle) {

        printLevle  = levle;
        logTag = Tag;
    }


    public void Logi(String messg)
    {
        if (printLevle <= LOGI)
            Log.i(logTag,messg);
    }

    public void Logw(String messg)
    {
        if (printLevle <= LOGW)
            Log.e(logTag,messg);
    }

    public void Loge(String messg)
    {
        if (printLevle <= LOGE)
            Log.e(logTag,messg);
    }


    public void info(String messg)
    {
        if (printLevle <= LOGI)
            Log.i(logTag,messg);
    }

    public void warning(String messg)
    {
        if (printLevle <= LOGW)
            Log.e(logTag,messg);
    }

    // https://www.jianshu.com/p/1a57504f3285

    public static StringBuffer getStackInfo()
    {
        int index = 3;
        StringBuffer stringBuffer = new StringBuffer();
        //打印栈帧中的所有方法调用
        try {
            StackTraceElement[] stackTrace = Thread.currentThread().getStackTrace();

//            Log.d("feifei","reseal statckIndex:"+index+",stackTrace.length:"+stackTrace.length);
//            for(int i = stackTrace.length-1;i>=0;i--){
//                System.out.println("index:"+i+"feifei ----,className:"+stackTrace[i].getClassName()+",method:"+stackTrace[i].getMethodName()+",fileName:"+stackTrace[i].getFileName()+",lineNumber:"+stackTrace[i].getLineNumber());
//            }

            String className = stackTrace[index].getFileName();
            String methodName = stackTrace[index].getMethodName();
            int lineNumber = stackTrace[index].getLineNumber();
            methodName = methodName.substring(0, 1).toUpperCase() + methodName.substring(1);
            stringBuffer.append("[(").append(className).append(":").append(lineNumber).append(")#").append(methodName).append("] ");
        } catch (Exception e) {
            e.printStackTrace();
        }

        return stringBuffer;
    }


    public static void debuge(String msg){
//        StringBuffer stringBuffer = getStackInfo();
//        if (staticPrintLevel < LOGD){
//            return;
//        }

        int index = 3;
        StringBuffer stringBuffer = new StringBuffer();
        //打印栈帧中的所有方法调用
        try {
            StackTraceElement[] stackTrace = Thread.currentThread().getStackTrace();

//            Log.d("feifei","reseal statckIndex:"+index+",stackTrace.length:"+stackTrace.length);
//            for(int i = stackTrace.length-1;i>=0;i--){
//                System.out.println("index:"+i+"feifei ----,className:"+stackTrace[i].getClassName()+",method:"+stackTrace[i].getMethodName()+",fileName:"+stackTrace[i].getFileName()+",lineNumber:"+stackTrace[i].getLineNumber());
//            }

            String className = stackTrace[index].getFileName();
            String methodName = stackTrace[index].getMethodName();
            int lineNumber = stackTrace[index].getLineNumber();
            methodName = methodName.substring(0, 1) + methodName.substring(1);
//            methodName = methodName.substring(0, 1).toUpperCase() + methodName.substring(1);
            stringBuffer.append("[(").append(className).append(":").append(lineNumber).append(")#").append(methodName).append("] ");
        } catch (Exception e) {
            e.printStackTrace();
        }

        String finalMsg = stringBuffer.toString()+": "+msg;
        Log.d(TAG,finalMsg);
    }



    public static void error(String msg){
//        StringBuffer stringBuffer = getStackInfo();
        if (staticPrintLevel < LOGD){
            return;
        }

        int index = 3;
        StringBuffer stringBuffer = new StringBuffer();
        //打印栈帧中的所有方法调用
        try {
            StackTraceElement[] stackTrace = Thread.currentThread().getStackTrace();

//            Log.d("feifei","reseal statckIndex:"+index+",stackTrace.length:"+stackTrace.length);
//            for(int i = stackTrace.length-1;i>=0;i--){
//                System.out.println("index:"+i+"feifei ----,className:"+stackTrace[i].getClassName()+",method:"+stackTrace[i].getMethodName()+",fileName:"+stackTrace[i].getFileName()+",lineNumber:"+stackTrace[i].getLineNumber());
//            }

            String className = stackTrace[index].getFileName();
            String methodName = stackTrace[index].getMethodName();
            int lineNumber = stackTrace[index].getLineNumber();
            methodName = methodName.substring(0, 1) + methodName.substring(1);
//            methodName = methodName.substring(0, 1).toUpperCase() + methodName.substring(1);
            stringBuffer.append("[(").append(className).append(":").append(lineNumber).append(")#").append(methodName).append("] ");
        } catch (Exception e) {
            e.printStackTrace();
        }

        String finalMsg = stringBuffer.toString()+": "+msg;
        Log.e(TAG,finalMsg);
    }


    public static void info(String tag,final Object... contents){
        StringBuffer stringBuffer = getStackInfo();
        String msg = processBody(contents);
        String finalMsg = stringBuffer.toString()+": "+msg;
        Log.d(tag,finalMsg);
    }


    private static String processBody(final Object... contents)
    {
        String body = "";
        StringBuilder sb = new StringBuilder();
        for (int i = 0, len = contents.length; i < len; ++i) {
            Object content = contents[i];
                sb.append("[")
                    .append(i)
                    .append("]")
                    .append(" = ")
                    .append(content)
                    .append(" ");
        }
        body = sb.toString();

        return body;
    }

    public static void xxd(String tag,String msg){

        int index = 3;
        StringBuffer stringBuffer = new StringBuffer();
        //打印栈帧中的所有方法调用
        try {
            StackTraceElement[] stackTrace = Thread.currentThread().getStackTrace();

//            Log.d("feifei","reseal statckIndex:"+index+",stackTrace.length:"+stackTrace.length);
//            for(int i = stackTrace.length-1;i>=0;i--){
//                System.out.println("index:"+i+"feifei ----,className:"+stackTrace[i].getClassName()+",method:"+stackTrace[i].getMethodName()+",fileName:"+stackTrace[i].getFileName()+",lineNumber:"+stackTrace[i].getLineNumber());
//            }

            String className = stackTrace[index].getFileName();
            String methodName = stackTrace[index].getMethodName();
            int lineNumber = stackTrace[index].getLineNumber();
            methodName = methodName.substring(0, 1).toUpperCase() + methodName.substring(1);
            stringBuffer.append("[(").append(className).append(":").append(lineNumber).append(")#").append(methodName).append("] ");
        } catch (Exception e) {
            e.printStackTrace();
        }

        String finalMsg = stringBuffer.toString()+": "+msg;
        Log.d(tag,finalMsg);
    }


}
