package theji.algorithmproject;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import theji.algorithmproject.repository.MemberRepository;
import theji.algorithmproject.repository.MemoryMemberRepository;
import theji.algorithmproject.service.MemberService;

@Configuration
public class SpringConfig {
    @Bean
    public MemberService memberService() {
        return new MemberService(memberRepository());
    }
    @Bean
    public MemberRepository memberRepository() {
        return new MemoryMemberRepository();
    }
}
