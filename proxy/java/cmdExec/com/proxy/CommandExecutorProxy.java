// package com.journaldev.design.proxy;
package com.proxy;

public class CommandExecutorProxy implements CommandExecutor {
	private boolean isAdmin;
	private CommandExecutor executor;
	//should be smarter than that...
	private final String adminUsername  = "admin";
	private final String adminPassword = "qwe098";
	
	public CommandExecutorProxy(String username, String password) {
		if(username.equals(adminUsername) && password.equals(adminPassword)) {
			isAdmin = true;
		}
		executor = new CommandExecutorImpl();	//we may use factory here
	}
	
	public void runCommand(String cmd) throws Exception{
		if(isAdmin) {
			executor.runCommand(cmd);
		}
		else {
			//check the type of the command before
			if(cmd.trim().startsWith("rm")) {
				throw new Exception("rm command is not allowed for non-admin users.");
			}
			else {
				executor.runCommand(cmd);
			}
		}
	}
}

