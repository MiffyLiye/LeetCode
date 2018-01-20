task :default => [:list]

def ensure_system_success(command)
    res = system command
    if !res
        raise
    end
end

desc 'List predefined tasks'
task :list do
    puts '== Predefined Tasks =='
    ensure_system_success 'rake --tasks'
end

desc 'Clean Build Outputs'
task :clean do
    puts '== Clean Build Outputs Started =='
    ensure_system_success "pwsh -c 'if (Test-Path build) { Remove-Item build -Recurse -Force -Verbose }'"
    ensure_system_success "pwsh -c 'New-Item -Type Directory build'"
    puts '== Clean Finished =='
end

desc 'Generate Makefile'
task :generate do
    puts '== Generate Makefile =='
    ensure_system_success "
            cd build
            cmake .. -G 'Unix Makefiles'
    "
    puts '== Generate Finished =='
end

desc 'Build'
task :build do
    puts '== Build Started =='
    ensure_system_success '
        cd build
        make
    '
    puts '== Build Finished =='
end

desc 'Clean and then Build'
task :rebuild => [:clean, :generate, :build] do
end

desc 'Test'
task :test do
    puts '== Test Started =='
    ensure_system_success '
        cd build
        ctest -VV
    '
    puts '== Test Finished =='
end
