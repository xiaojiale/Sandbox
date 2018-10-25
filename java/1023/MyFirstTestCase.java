package com.ericsson.jcat.handson.testcases;
import org.testing.annotations.Test;

public class MyFirstTestCase extends se.ericsson.jcat.fw.ng.JcatNGTestBase {
    public void myFirstTest() {
        setTestCase("TC-MYFIRST-001", "A failing JCAT test case");

        setTestStepBegin("Print Hello World!");
        setTestInfo("Hello World!");
        setTestStepEnd();
    }

    public void tryJacaDoc() {
        // class body
    }
}
        
