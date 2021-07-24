// package com.journaldev.design.proxy;
package com.proxy;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class CommandExecutorImpl implements CommandExecutor {
	@Override
	public void runCommand(String cmd) throws IOException{
		//some heavy implementation
        Process p = Runtime.getRuntime().exec(cmd);
        BufferedReader in = new BufferedReader(
                            new InputStreamReader(p.getInputStream()));
        String line = null;
        while ((line = in.readLine()) != null) {
            System.out.println(line);
        }
		System.out.println("'" + cmd + "' command executed.");
	}
}
