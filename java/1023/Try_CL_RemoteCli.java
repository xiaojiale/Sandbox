package com.ericsson.jcat.handson.testcases;
import com.ericsson.commonlibrary.remotecli.Cli;
import com.ericsson.commonlibrary.remotecli.CliBuilder;
import com.ericsson.commonlibrary.remotecli.CliFactory;

public class Try_CL_RemoteCli {
    public static void main(String[] args) {
      String host = "10.186.135.2";
      String username = "lte";
      String password = "lte123";

      final CliBuilder builder = CliFactory.newSshBuilder();
      builder.setHost(host).setUsername(username).setPassword(password);

      final Cli cli = builder.build();
      cli.connect();

      final String output = cli.send("ls");
      System.out.println("output: " + output);

      cli.disconnect();
    }
}
