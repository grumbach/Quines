const fs	= require('fs');
const exec	= require('child_process').exec;
const X		= 5

let main = () =>
{
	let write = (name, code) =>
	{
		fs.writeFile(name, code, (err) => {
			if (err)
				return console.log(err)
			let child = exec('node ' + name, (error, stdout, stderr) => {
				if (error)
					return console.log(err)
				})
			})
	}

	function getfilename()
	{
		var orig = Error.prepareStackTrace
		Error.prepareStackTrace = function(_, stack){ return stack; }
		var err = new Error
		Error.captureStackTrace(err, arguments.callee)
		var stack = err.stack
		Error.prepareStackTrace = orig
		return stack[1].getFileName().split('/').slice(-1)[0]
	}

	let filename = getfilename()
	if (X == 5 && filename == "Sully.js") {
		let name = "Sully_" + (X) + ".js"
		let code = "const fs	= require('fs');\nconst exec	= require('child_process').exec;\nconst X		= " + (X) + "\n\nlet main = " + main + "\n\nmain()\n"
		write(name, code)
	} else if (X > 0) {
		let name = "Sully_" + (X-1) + ".js"
		let code = "const fs	= require('fs');\nconst exec	= require('child_process').exec;\nconst X		= " + (X - 1) + "\n\nlet main = " + main + "\n\nmain()\n"
		write(name, code)
	}
}

main()
