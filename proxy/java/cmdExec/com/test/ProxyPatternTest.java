// package com.journaldev.design.test;
package com.test;

// import com.journaldev.design.proxy.CommandExecutor;
// import com.journaldev.design.proxy.CommandExecutorProxy;
// import com.journaldev.design.proxy.CommandExecutorImpl;
import com.proxy.CommandExecutor;
import com.proxy.CommandExecutorProxy;
import com.proxy.CommandExecutorImpl;

public class ProxyPatternTest {
	public static void main(String[] args) {
		System.out.println("\n---- command executor test ----");
		System.out.println("[main] creating a user...");
		CommandExecutor executor = new CommandExecutorProxy("admin","wrong_password");
//		CommandExecutor executor = new CommandExecutorImpl();
		try {
			System.out.println("\n[main] trying to run command cmd /C dir");
			executor.runCommand("cmd /C dir");
			System.out.println("\n[main] trying to run command rm -rf");
			executor.runCommand("   rm -rf abs.pdf");
		}catch(Exception e) {
			System.out.println("[main] Exception Message: "+e.getMessage());
		}
	}
}

