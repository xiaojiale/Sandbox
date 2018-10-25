package com.ericsson.jacat.handson.testcases;
import com.ericsson.commonlibrary.moshell.Moshell;
import com.ericsson.commonlibrary.moshell.UserVariable;
import com.ericsson.commonlibrary.remotecli.Cli;
import com.ericsson.commonlibrary.remotecli.CliBuilder;
import com.ericsson.commonlibrary.remotecli.CliFactory;

public class Try_CL_Moshell {
    private static final String IP = "10.186.137.109";
    private static final String MOSHELL_PATH = "/home/lte/moshell/moshell";
    private static final String PASSWORD = "rbs";

    public static void main(String[] args) {
        String host = "10.186.135.2";
        String username = "lte";
        String password = "lte123";

        final CliBuilder builder = CliFactory.newSshBuilder();
        builder.setHost(host).setUsername(username).setPassword(password);

        final Cli cli = builder.build();
        cli.connect();

        Moshell m = Moshell.newBuilder()
                           .setRemoteCli(cli)
                           .setBinaryName(MOSHELL_PATH)
                           .enableUserVariable(UserVariable.IP, IP)
                           .ebableUserVariable(UserVariable.PASSWORD, PASSWORD)
                           .build();

        m.connect();

        String retVal = m.send("lt all");
        System.out.println(retVal);
        retVal = m.send("lst cell");
        System.out.println(retVal);
        m.disconnect();
        cli.disconnect();
    }
}




                      String retVal = m.send("lt all");
                              System.out.println(retVal);
                                      retVal = m.send("lst cell");
                                              System.out.println(retVal);
                                                      m.disconnect();
                                                              cli.disconnect();

